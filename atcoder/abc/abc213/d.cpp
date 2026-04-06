#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

graph T;

void dfs(int u,int p){
	printf("%d ",u+1);
	for(int v:T[u]) if(v!=p) {
		dfs(v,u);
		printf("%d ",u+1);
	}
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}
	rep(u,n){
		sort(T[u].begin(),T[u].end());
	}

	dfs(0,-1);

	return 0;
}
