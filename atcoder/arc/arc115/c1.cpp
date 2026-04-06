#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

int main(){
	int n; scanf("%d",&n);

	graph G(n+1);
	for(int u=1;u<=n;u++){
		for(int v=2*u;v<=n;v+=u){
			add_directed_edge(G,u,v);
		}
	}

	vector<int> dp(n+1);
	for(int u=1;u<=n;u++){
		for(int v:G[u]){
			dp[v]=max(dp[v],dp[u]+1);
		}
		printf("%d%c",dp[u]+1,u<n?' ':'\n');
	}

	return 0;
}
