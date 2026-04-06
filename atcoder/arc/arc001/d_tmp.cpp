#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;
using lint=long long;

struct point{ lint x,y; };

bool ccw(point p,point q,point r){
	point v{q.x-p.x,q.y-p.y};
	point w{r.x-q.x,r.y-q.y};
	return v.x*w.y-v.y*w.x>0;
}

double dist(point p,point q){ return hypot(p.x-q.x,p.y-q.y); }

int main(){
printf("%d\n",ccw(point{0,0},point{0,1},point{-1,1}));
	int n,s,t; scanf("%d%d%d",&n,&s,&t);
	vector<int> l(n+1),r(n+1);
	rep(i,n+1) scanf("%d%d",&l[i],&r[i]);
	l[n]=r[n]=t;

	vector<pair<point,double>> L,R;
	L.emplace_back(point{s,0},0);
	R.emplace_back(point{s,0},0);
	for(int i=1;i<=n;i++){
		point p{l[i],i},q{r[i],i};
		while(L.size()>=2 && ccw(p,L.back().first,L[L.size()-2].first)) L.pop_back();
		while(R.size()>=2 && ccw(R[R.size()-2].first,R.back().first,q)) R.pop_back();

		// add p
		if(R.size()>=2 && ccw(R[1].first,R[0].first,p)){
			int i;
			for(i=0;i+1<R.size()&&ccw(R[i+1].first,R[i].first,p);i++);
			L={R[i]};
			L.emplace_back(p,R[i].second+dist(R[i].first,p));
		}
		else{
			L.emplace_back(p,L.back().second+dist(L.back().first,p));
		}

		// add q
		if(L.size()>=2 && ccw(q,L[0].first,L[1].first)){
			int i;
			for(i=0;i+1<L.size()&&ccw(q,L[i].first,L[i+1].first);i++);
			R={L[i]};
			R.emplace_back(q,L[i].second+dist(L[i].first,q));
		}
		else{
			R.emplace_back(q,R.back().second+dist(R.back().first,q));
		}

printf("i=%d: %d, %d\n",i,L.size(),R.size());
printf("L:\n"); for(auto x:L) printf("  (%d, %d)\n",x.first.x,x.first.y);
printf("R:\n"); for(auto x:R) printf("  (%d, %d)\n",x.first.x,x.first.y);
	}
	printf("%.15f\n",min(L.back().second,R.back().second));

	return 0;
}
