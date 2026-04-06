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

vector<int> topological_order(const graph& D){
	int n=D.size();
	vector<int> deg(n);
	rep(u,n) for(int v:D[u]) deg[v]++;

	vector<int> res;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		res.emplace_back(u);
		for(int v:D[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return res;
}

vector<int> Grundy(const graph& D){
	auto ord=topological_order(D);

	int n=D.size(),m=0;
	rep(u,n) m=max(m,int(D[u].size()));

	vector<int> g(n),last(m+1,-1);
	rep(i,n){
		int u=ord[n-i-1];
		for(int v:D[u]) last[g[v]]=u;
		while(last[g[u]]==u) g[u]++;
	}
	return g;
}

int main(){
	int n; scanf("%d",&n);

	graph G(n+1);
	for(int u=1;u<=n;u++){
		for(int v=2*u;v<=n;v+=u){
			add_directed_edge(G,v,u);
		}
	}

	auto g=Grundy(G);
	for(int u=1;u<=n;u++) printf("%d%c",g[u]+1,u<n?' ':'\n');

	return 0;
}
