#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

pair<int,pair<int,int>> tree_diameter(const graph& T){
	function<pair<int,int>(int,int)> dfs=[&](int u,int p){
		int dep=0,w=u;
		for(int v:T[u]) if(v!=p) {
			auto tmp=dfs(v,u);
			tmp.first++;
			if(tmp.first>dep) tie(dep,w)=tmp;
		}
		return make_pair(dep,w);
	};
	int u=dfs(0,-1).second;
	auto res=dfs(u,-1);
	return {res.first,{u,res.second}};
}

graph T;
vector<int> P;

bool dfs1(int u,int p,int g){
	if(u==g){
		P.emplace_back(g);
		return true;
	}

	for(int v:T[u]) if(v!=p) {
		if(dfs1(v,u,g)){
			P.emplace_back(u);
			return true;
		}
	}
	return false;
}

int ans[200000],i_ans,i_path;

void dfs2(int u,int p){
	ans[u]=i_ans++;
	for(int v:T[u]) if(v!=p && v!=P[i_path]) {
		dfs2(v,u);
		i_ans++;
	}
	if(i_path<P.size() && u==P[i_path-1]){
		dfs2(P[i_path++],u);
	}
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	auto [u0,u1]=tree_diameter(T).second;

	dfs1(u0,-1,u1);
	reverse(P.begin(),P.end());

	i_ans=i_path=1;
	dfs2(u0,-1);
	rep(u,n) printf("%d%c",ans[u],u<n-1?' ':'\n');

	return 0;
}
