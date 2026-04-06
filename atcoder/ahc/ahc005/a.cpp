#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const int INF=1<<29;
const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

random_device seed_gen;
mt19937 rng(seed_gen());

struct point{
	int x,y;
	point(){}
	point(int x,int y):x(x),y(y){}
	bool operator< (const point& p)const{ return make_pair(x,y)< make_pair(p.x,p.y); }
	bool operator==(const point& p)const{ return make_pair(x,y)==make_pair(p.x,p.y); }
	bool operator!=(const point& p)const{ return !(*this==p); }
};

enum{V_TYPE,H_TYPE};
struct line{
	int type,t,l,b,r;
	line(){}
	line(int type,int t,int l,int b,int r):type(type),t(t),l(l),b(b),r(r){}
	bool operator< (const line& a)const{ return make_tuple(type,t,l,b,r)< make_tuple(a.type,a.t,a.l,a.b,a.r); }
	bool operator==(const line& a)const{ return make_tuple(type,t,l,b,r)==make_tuple(a.type,a.t,a.l,a.b,a.r); }
	bool operator!=(const line& a)const{ return !(*this==a); }
};

int h,w;
point s;
vector<string> B;

vector<line> L;
vector<int> point_to_line[71][71];

static int _d[71][71][71][71];
static point _pre[71][71][71][71];
int distance(const point& from,const point& to){
	assert(B[from.x][from.y]!='#');

	if(_d[from.x][from.y][from.x][from.y]!=INF){
		return _d[from.x][from.y][to.x][to.y];
	}

	_d[from.x][from.y][from.x][from.y]=0;
	priority_queue<pair<int,point>> Q;
	Q.emplace(0,from);
	while(!Q.empty()){
		int d0;
		point p;
		tie(d0,p)=Q.top(); Q.pop();
		d0*=-1;

		if(_d[from.x][from.y][p.x][p.y]<d0) continue;

		rep(k,4){
			int x2=p.x+dx[k],y2=p.y+dy[k];
			if(B[x2][y2]!='#'){
				int d2=d0+(B[x2][y2]-'0');
				if(_d[from.x][from.y][x2][y2]>d2){
					_d[from.x][from.y][x2][y2]=d2;
					_pre[from.x][from.y][x2][y2]=p;
					Q.emplace(-d2,point(x2,y2));
				}
			}
		}
	}
	return _d[from.x][from.y][to.x][to.y];
}

int distance(const point& from,int line_idx){
	const line& to=L[line_idx];

	int m=L.size();
	static vector memo(h,vector(w,vector(m,-1)));
	if(memo[from.x][from.y][line_idx]!=-1) return memo[from.x][from.y][line_idx];

	int d=INF;
	if(to.type==V_TYPE){
		int x,y=to.l;
		for(x=to.t;x<=to.b;x++) d=min(d,distance(from,point(x,y)));
	}
	else if(to.type==H_TYPE){
		int x=to.t,y;
		for(y=to.l;y<=to.r;y++) d=min(d,distance(from,point(x,y)));
	}
	else abort();
	return memo[from.x][from.y][line_idx]=d;
}

vector<point> find_path(const point& from,point to){
	distance(from,to);

	vector<point> res;
	while(to!=from){
		res.emplace_back(to);
		to=_pre[from.x][from.y][to.x][to.y];
	}
	reverse(res.begin(),res.end());
	return res;
}

vector<point> find_path(const point& from,int line_idx){
	const line& to=L[line_idx];

	int m=L.size();
	static vector memo(h,vector(w,vector(m,vector<point>())));
	if(!memo[from.x][from.y][line_idx].empty()) return memo[from.x][from.y][line_idx];

	int d=INF;
	point p;
	if(to.type==V_TYPE){
		int y=to.l;
		for(int x=to.t;x<=to.b;x++){
			if(d>distance(from,point(x,y))){ d=distance(from,point(x,y)); p=point(x,y); }
		}
	}
	else if(to.type==H_TYPE){
		int x=to.t;
		for(int y=to.l;y<=to.r;y++){
			if(d>distance(from,point(x,y))){ d=distance(from,point(x,y)); p=point(x,y); }
		}
	}
	else abort();

	return memo[from.x][from.y][line_idx]=find_path(from,p);
}

void precalc(){
	rep(i,h) rep(j,w) rep(x,h) rep(y,w) {
		_d[i][j][x][y]=INF;
	}

	rep(i,h) rep(j,w) if(B[i][j]!='#') {
		int x[4],y[4];
		rep(k,4){
			x[k]=i;
			y[k]=j;
			while(B[x[k]][y[k]]!='#'){
				x[k]+=dx[k];
				y[k]+=dy[k];
			}
		}
		if(x[1]+1<i || i<x[3]-1){
			L.emplace_back(V_TYPE,x[1]+1,j,x[3]-1,j);
		}
		if(y[2]+1<j || j<y[0]-1){
			L.emplace_back(H_TYPE,i,y[2]+1,i,y[0]-1);
		}
	}
	sort(L.begin(),L.end());
	L.erase(unique(L.begin(),L.end()),L.end());

	rep(i,L.size()){
		if(L[i].type==V_TYPE){
			int y=L[i].l;
			for(int x=L[i].t;x<=L[i].b;x++) point_to_line[x][y].emplace_back(i);
		}
		else if(L[i].type==H_TYPE){
			int x=L[i].t;
			for(int y=L[i].l;y<=L[i].r;y++) point_to_line[x][y].emplace_back(i);
		}
		else abort();
	}
}

void input(){
	int n; cin>>n>>s.x>>s.y;
	h=w=n+2;
	s.x++;
	s.y++;
	B.assign(h,string(w,'#'));
	rep(i,n){
		string s; cin>>s;
		rep(j,n) B[i+1][j+1]=s[j];
	}
}

void output(const vector<point>& P){
	assert(P.size()>0);
	rep(i,P.size()-1){
		char c;
		if     (P[i+1].x>P[i].x) c='D';
		else if(P[i+1].x<P[i].x) c='U';
		else if(P[i+1].y>P[i].y) c='R';
		else if(P[i+1].y<P[i].y) c='L';
		else abort();
		cout<<c;
	}
	cout<<'\n';
}

lint calc_score(const vector<point>& P){
	lint n=h-2,d=0;
	rep(i,P.size()-1) d+=B[P[i+1].x][P[i+1].y]-'0';
	return 10000+10000000*n/d;
}

double PARAM;
double cost(const point& p,int line_idx){
	const line& to=L[line_idx];
	if(to.type==V_TYPE) return distance(p,line_idx)+PARAM*min(to.l,w-to.l);
	else                return distance(p,line_idx)+PARAM*min(to.t,h-to.t);
}

pair<vector<point>,vector<int>> solve_greedy(){
	int m=L.size();
	vector<bool> vis(m);
	set<int> Unvis;
	rep(i,m) Unvis.emplace(i);
	for(int i:point_to_line[s.x][s.y]){
		vis[i]=true;
		Unvis.erase(i);
	}

	vector<point> res={s};
	vector<int> seq;
	while(1){
		if(Unvis.empty()) break;

		point cur=res.back();
		int idx=-1;
		for(int i:Unvis){
			if(idx==-1 || cost(cur,i)<cost(cur,idx)){
				idx=i;
			}
		}
		auto tmp=find_path(cur,idx);
		res.insert(res.end(),tmp.begin(),tmp.end());
		seq.emplace_back(idx);

		for(auto p:tmp){
			for(int i:point_to_line[p.x][p.y]) if(!vis[i]) {
				vis[i]=true;
				Unvis.erase(i);
			}
		}
	}

	auto back=find_path(res.back(),s);
	res.insert(res.end(),back.begin(),back.end());

	return {res,seq};
}

pair<vector<point>,vector<int>> solve_random(vector<int> seq){ // seq: 選ぶ line の番号の列
	int m=L.size();
	vector<bool> vis(m);
	set<int> Unvis;
	rep(i,m) Unvis.emplace(i);
	for(int i:point_to_line[s.x][s.y]){
		vis[i]=true;
		Unvis.erase(i);
	}

	int t_break=0.7*seq.size()+0.3*(rng()%seq.size());

	vector<point> res={s};
	vector<int> seq2;
	for(int t=0;;t++){
		if(Unvis.empty()) break;

		point cur=res.back();

		int idx=-1;
		if(t<t_break){
			idx=seq[t];
		}
		else if(t=t_break){ // t_break 回目に選ぶ line は残っているものの中から一様ランダムに選ぶ
			auto it=Unvis.begin();
			for(int i=rng()%Unvis.size();i>0;i--) ++it;
			idx=*it;
		}
		else{
			for(int i:Unvis){
				if(idx==-1 || cost(cur,i)<cost(cur,idx)){
					idx=i;
				}
			}
		}
		auto tmp=find_path(cur,idx);
		res.insert(res.end(),tmp.begin(),tmp.end());
		seq2.emplace_back(idx);

		for(auto p:tmp){
			for(int i:point_to_line[p.x][p.y]) if(!vis[i]) {
				vis[i]=true;
				Unvis.erase(i);
			}
		}
	}

	auto back=find_path(res.back(),s);
	res.insert(res.end(),back.begin(),back.end());

	return {res,seq2};
}

int main(){
	auto t0=chrono::system_clock::now();

	input();
	precalc();

	double PARAM_opt;
	vector<point> P_opt;
	vector<int> seq_opt;
	lint score_opt=-1;

	rep(i,2000){
		PARAM=0.05*i;
		auto [P,seq]=solve_greedy();
		lint score=calc_score(P);
		if(score_opt<score){
			PARAM_opt=PARAM;
			P_opt=P;
			seq_opt=seq;
			score_opt=score;
		}
	}

	PARAM=PARAM_opt;
	while(1){
		auto [P,seq]=solve_random(seq_opt);
		lint score=calc_score(P);
		if(score_opt<score){
			P_opt=P;
			seq_opt=seq;
			score_opt=score;
		}

		auto t=chrono::system_clock::now();
		if(chrono::duration_cast<chrono::milliseconds>(t-t0).count()>2900) break;
	}


	output(P_opt);
	// fprintf(stderr,"score = %lld\n",score_opt);

	return 0;
}
