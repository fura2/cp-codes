#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector d(n,vector(n,INF));
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		d[u][v]=c;
	}
	rep(u,n) d[u][u]=0;

	lint ans=0;
	rep(k,n){
		rep(i,n) rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		rep(i,n) rep(j,n) if(d[i][j]<INF) ans+=d[i][j];
	}
	printf("%lld\n",ans);

	return 0;
}
