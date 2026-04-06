#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

pair<int,vector<int>> tree_diameter(const graph& T){
	int n=T.size();
	vector<int> pre(n,-1);

	auto dfs=[&](auto&& dfs,int u,int p)->pair<int,int>{
		int g=u,d_max=0;
		for(int v:T[u]) if(v!=p) {
			auto [d,w]=dfs(dfs,v,u);
			if(d+1>d_max){
				d_max=d+1;
				g=w;
			}
			pre[v]=u;
		}
		return {d_max,g};
	};
	int u0=dfs(dfs,0,-1).second;
	auto [diam,u1]=dfs(dfs,u0,-1);

	vector<int> P={u1};
	for(int u=u1;u!=u0;u=pre[u]){
		P.emplace_back(pre[u]);
	}
	reverse(P.begin(),P.end());

	return {diam,P};
}

graph T;
vector<int> P;

int ans[200000],i_ans,i_path;

void dfs(int u,int p){
	ans[u]=i_ans++;
	for(int v:T[u]) if(v!=p && v!=P[i_path]) {
		dfs(v,u);
		i_ans++;
	}
	if(i_path<P.size() && u==P[i_path-1]){
		dfs(P[i_path++],u);
	}
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	P=tree_diameter(T).second;

	i_ans=i_path=1;
	dfs(P[0],-1);
	rep(u,n) printf("%d%c",ans[u],u<n-1?' ':'\n');

	return 0;
}
