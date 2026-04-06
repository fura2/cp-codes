#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double INF=1e77;

int main(){
	double xs,ys,xt,yt;
	int n; cin>>xs>>ys>>xt>>yt>>n;
	double x[1002],y[1002],r[1002];
	rep(u,n) cin>>x[u]>>y[u]>>r[u];
	x[n]=xs; y[n]=ys; r[n]=0; n++; // start
	x[n]=xt; y[n]=yt; r[n]=0; n++; // goal

	double d[1002];
	rep(u,n) d[u]=(u==n-2?0:INF);
	priority_queue<pair<double,int>> Q;
	Q.emplace(0,n-2);
	while(!Q.empty()){
		auto a=Q.top(); Q.pop();
		double d0=-a.first;
		int u=a.second;

		if(u==n-1){ cout<<setprecision(10)<<d0<<endl; break; }
		if(d0>d[u]) continue;

		rep(v,n){
			double d1=d0+max(hypot(x[v]-x[u],y[v]-y[u])-r[u]-r[v],0.0);
			if(d1<d[v]){
				d[v]=d1;
				Q.emplace(-d1,v);
			}
		}
	}

	return 0;
}
