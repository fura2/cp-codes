#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

graph G;

bool vis[20];

void dfs1(int u,vector<int>& order){
	vis[u]=true;
	order.emplace_back(u);
	for(int v:G[u]) if(!vis[v]) dfs1(v,order);
}

int color[20];

lint dfs2(int i,vector<int>& order){
	if(i==order.size()) return 1;

	int u=order[i];
	bool b[3]={};
	for(int v:G[u]) if(color[v]!=-1) b[color[v]]=true;

	lint res=0;
	rep(c,3) if(!b[c]) {
		color[u]=c;
		res+=dfs2(i+1,order);
		color[u]=-1;
	}
	return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	G.resize(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}

	lint ans=1;
	memset(color,-1,sizeof color);
	rep(u,n) if(!vis[u]) {
		vector<int> order;
		dfs1(u,order);
		ans*=dfs2(0,order);
	}
	printf("%lld\n",ans);

	return 0;
}
