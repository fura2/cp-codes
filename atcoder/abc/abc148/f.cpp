#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

graph T;

int dist[2][100000];
void dfs(int u,int p,int d,int type){
	dist[type][u]=d;
	for(int v:T[u]) if(v!=p) dfs(v,u,d+1,type);
}

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b); a--; b--;
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	dfs(a,-1,0,0);
	dfs(b,-1,0,1);

	int ans=0;
	rep(u,n) if(dist[0][u]<dist[1][u]) ans=max(ans,dist[1][u]-1);
	printf("%d\n",ans);

	return 0;
}
