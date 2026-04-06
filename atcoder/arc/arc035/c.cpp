#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	lint d[400][400];
	rep(u,n) rep(v,n) d[u][v]=(u==v?0:INF);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		d[u][v]=d[v][u]=c;
	}

	rep(w,n) rep(u,n) rep(v,n) d[u][v]=min(d[u][v],d[u][w]+d[w][v]);

	int q; scanf("%d",&q);
	rep(_,q){
		int x,y,z; scanf("%d%d%d",&x,&y,&z); x--; y--;
		lint sum=0;
		rep(u,n) rep(v,n) {
			d[u][v]=min({d[u][v],d[u][x]+z+d[y][v],d[u][y]+z+d[x][v]});
			sum+=d[u][v];
		}
		printf("%lld\n",sum/2);
	}

	return 0;
}
