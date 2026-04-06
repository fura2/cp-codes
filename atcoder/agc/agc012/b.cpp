#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_edge(G,u,v);
	}

	int q; scanf("%d",&q);
	vector<int> v0(q),d(q),c(q);
	rep(i,q) scanf("%d%d%d",&v0[i],&d[i],&c[i]), v0[i]--;

	vector<int> color(n);
	vector<vector<bool>> vis(n,vector<bool>(11));

	for(int i=q-1;i>=0;i--) if(!vis[v0[i]][d[i]]) {
		vis[v0[i]][d[i]]=true;

		queue<pair<int,int>> Q; Q.emplace(v0[i],d[i]);
		while(!Q.empty()){
			int u,k; tie(u,k)=Q.front(); Q.pop();

			if(color[u]==0) color[u]=c[i];
			if(k==0) continue;

			for(int v:G[u]) if(!vis[v][k-1]) {
				vis[v][k-1]=true;
				Q.emplace(v,k-1);
			}
		}
	}

	rep(u,n) printf("%d\n",color[u]);

	return 0;
}
