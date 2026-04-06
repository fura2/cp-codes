#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct point{
	int x,y;
	bool operator<(const point &a)const{ return x!=a.x?x<a.x:y<a.y; }
};
bool cmp_y(const point &a,const point &b){ return a.y!=b.y?a.y<b.y:a.x<b.x; }

int D;
set<point> S;

map<int,set<int>> XtoY,YtoX; // XtoY: x -> (y-coordinate of points which have x-coordinate x)
map<int,vector<int>> XtoY2,YtoX2; // same as above (use vector instead of set)

long long ans=0;

void dfs(point p){
	int x=p.x,y=p.y;
	set<point> next;

	// (x-D, y)
	if(XtoY.count(x-D)>0){
		auto &Y=XtoY[x-D];
		for(auto it=Y.lower_bound(y-D);it!=Y.end()&&*it<=y+D;++it){
			next.emplace(point{x-D,*it});
		}
		auto &Y2=XtoY2[x-D];
		int l=lower_bound(Y2.begin(),Y2.end(),y-D)-Y2.begin();
		int r=upper_bound(Y2.begin(),Y2.end(),y+D)-Y2.begin();
		ans+=r-l;
	}

	// (x+D, y)
	if(XtoY.count(x+D)>0){
		auto &Y=XtoY[x+D];
		for(auto it=Y.lower_bound(y-D);it!=Y.end()&&*it<=y+D;++it){
			next.emplace(point{x+D,*it});
		}
		auto &Y2=XtoY2[x+D];
		int l=lower_bound(Y2.begin(),Y2.end(),y-D)-Y2.begin();
		int r=upper_bound(Y2.begin(),Y2.end(),y+D)-Y2.begin();
		ans+=r-l;
	}

	// (x, y-D)
	if(YtoX.count(y-D)>0){
		auto &X=YtoX[y-D];
		for(auto it=X.lower_bound(x-D);it!=X.end()&&*it<=x+D;++it){
			next.emplace(point{*it,y-D});
		}
		auto &X2=YtoX2[y-D];
		int l=lower_bound(X2.begin(),X2.end(),x-D)-X2.begin();
		int r=upper_bound(X2.begin(),X2.end(),x+D)-X2.begin();
		ans+=r-l;
	}

	// (x, y+D)
	if(YtoX.count(y+D)>0){
		auto &X=YtoX[y+D];
		for(auto it=X.lower_bound(x-D);it!=X.end()&&*it<=x+D;++it){
			next.emplace(point{*it,y+D});
		}
		auto &X2=YtoX2[y+D];
		int l=lower_bound(X2.begin(),X2.end(),x-D)-X2.begin();
		int r=upper_bound(X2.begin(),X2.end(),x+D)-X2.begin();
		ans+=r-l;
	}

	if(S.count({x-D,y-D})>0) ans--;
	if(S.count({x+D,y-D})>0) ans--;
	if(S.count({x-D,y+D})>0) ans--;
	if(S.count({x+D,y+D})>0) ans--;

	// delete next vertices from XtoY and YtoX
	for(point q:next){
		XtoY[q.x].erase(q.y);
		YtoX[q.y].erase(q.x);
	}

	for(point q:next) dfs(q);
}

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b); a--; b--;
	vector<point> P(n);
	rep(i,n){
		int x,y; scanf("%d%d",&x,&y);
		P[i]={x+y,x-y};
		S.emplace(P[i]);
	}
	D=max(abs(P[a].x-P[b].x),abs(P[a].y-P[b].y));

	{ // calc XtoY and XtoY2
		auto Q=P;
		sort(Q.begin(),Q.end());
		int pre=0;
		rep(i,n) if(i==n-1 || Q[i].x<Q[i+1].x) {
			vector<int> tmp;
			for(int j=pre;j<=i;j++) tmp.emplace_back(Q[j].y);
			XtoY[Q[i].x]=set<int>(tmp.begin(),tmp.end());
			XtoY2[Q[i].x]=tmp;
			pre=i+1;
		}
	}

	{ // calc YtoX and YtoX2
		auto Q=P;
		sort(Q.begin(),Q.end(),cmp_y);
		int pre=0;
		rep(i,n) if(i==n-1 || Q[i].y<Q[i+1].y) {
			vector<int> tmp;
			for(int j=pre;j<=i;j++) tmp.emplace_back(Q[j].x);
			YtoX[Q[i].y]=set<int>(tmp.begin(),tmp.end());
			YtoX2[Q[i].y]=tmp;
			pre=i+1;
		}
	}

	XtoY[P[a].x].erase(P[a].y);
	YtoX[P[a].y].erase(P[a].x);

	dfs(P[a]);
	cout<<ans/2<<endl;

	return 0;
}
