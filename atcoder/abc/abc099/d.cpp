#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int a[30][30],c[500][500];
	rep(i,m) rep(j,m) scanf("%d",a[i]+j);
	rep(i,n) rep(j,n) scanf("%d",c[i]+j), c[i][j]--;

	if(n==1){ puts("0"); return 0; }

	vector<int> gr[3];
	rep(i,n) rep(j,n) gr[(i+j)%3].emplace_back(c[i][j]);

	int cost[3][30]={};
	rep(i,3) rep(j,m) rep(k,gr[i].size()) cost[i][j]+=a[gr[i][k]][j];

	int ans=INF;
	rep(i,m) rep(j,m) rep(k,m) if(i!=j && j!=k && k!=i) ans=min(ans,cost[0][i]+cost[1][j]+cost[2][k]);
	printf("%d\n",ans);

	return 0;
}
