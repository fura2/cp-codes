#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int d[300][300];
	rep(i,n) rep(j,n) d[i][j]=(i==j?0:INF);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		d[u][v]=d[v][u]=c;
	}

	rep(k,n) rep(i,n) rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

	int ans=INF;
	rep(u,n) ans=min(ans,*max_element(d[u],d[u]+n));
	printf("%d\n",ans);

	return 0;
}
