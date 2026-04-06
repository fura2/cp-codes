#include <algorithm>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m,a[1000],b[1000],c[1000];
	scanf("%d%d",&n,&m);
	rep(i,m) scanf("%d%d%d",&a[i],&b[i],&c[i]), a[i]--, b[i]--;

	int d[100][100];
	rep(u,n) rep(v,n) d[u][v]=d[v][u]=(u==v?0:INF);
	rep(i,m) d[a[i]][b[i]]=d[b[i]][a[i]]=c[i];

	rep(k,n) rep(i,n) rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

	int ans=0;
	rep(i,m) if(c[i]>d[a[i]][b[i]]) ans++;
	printf("%d\n",ans);

	return 0;
}
