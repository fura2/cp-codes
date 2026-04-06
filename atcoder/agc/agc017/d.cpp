// Green Hackenbush

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

graph T;

int dfs(int u,int p){
	int g=0;
	for(int v:T[u]) if(v!=p) g^=dfs(v,u)+1;
	return g;
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	puts(dfs(0,-1)!=0?"Alice":"Bob");

	return 0;
}
