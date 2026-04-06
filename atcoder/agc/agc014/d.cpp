#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int main(){
	int n; scanf("%d",&n);
	graph T(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	vector<int> deg(n);
	rep(u,n) for(int v:T[u]) deg[v]++;

	vector<int> color(n,-1);
	queue<int> Q;
	rep(u,n) if(deg[u]==1) {
		Q.emplace(u);
	}
	while(!Q.empty()){
		int u=Q.front(); Q.pop();

		int p=-1;
		for(int v:T[u]) if(deg[v]>0) p=v;

		if(color[u]==-1){
			if(p==-1 || color[p]==0){
				puts("First");
				return 0;
			}
			else{ // color[p]==-1
				color[p]=0;
				color[u]=1;
			}
		}
		else{ // color[u]==0
			if(p==-1) break;
		}

		deg[u]--;
		deg[p]--;
		if(deg[p]==1) Q.emplace(p);
	}
	puts("Second");

	return 0;
}
