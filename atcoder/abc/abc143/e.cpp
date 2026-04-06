#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

int main(){
	int n,m,L; cin>>n>>m>>L;
	lint d1[300][300];
	rep(u,n) rep(v,n) d1[u][v]=(u==v?0:INF);
	rep(i,m){
		int u,v,c; cin>>u>>v>>c; u--; v--;
		d1[u][v]=d1[v][u]=c;
	}

	rep(w,n) rep(u,n) rep(v,n) d1[u][v]=min(d1[u][v],d1[u][w]+d1[w][v]);

	lint d2[300][300];
	rep(u,n) rep(v,n) d2[u][v]=(u==v?0:d1[u][v]<=L?1:INF);
	rep(w,n) rep(u,n) rep(v,n) d2[u][v]=min(d2[u][v],d2[u][w]+d2[w][v]);

	int q; cin>>q;
	rep(_,q){
		int s,t; cin>>s>>t; s--; t--;
		cout<<(d2[s][t]<INF?d2[s][t]-1:-1)<<endl;
	}
	return 0;
}
