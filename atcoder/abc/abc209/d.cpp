#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

template<class T>
class lowest_common_ancestor{ lowest_common_ancestor(const T&,int)=delete; };

template<>
class lowest_common_ancestor<graph>{
	vector<int> dep;
	vector<vector<int>> par;

public:
	lowest_common_ancestor(){}
	lowest_common_ancestor(const graph& T,int root){ build(T,root); }

	void build(const graph& T,int root){
		int n=T.size(),h;
		for(h=1;(1<<h)<n;h++);

		dep.assign(n,0);
		par.assign(h,vector<int>(n,-1));

		auto dfs=[&](auto&& dfs,int u,int p)->void{
			for(int v:T[u]) if(v!=p) {
				dep[v]=dep[u]+1;
				par[0][v]=u;
				dfs(dfs,v,u);
			}
		};

		dfs(dfs,root,-1);
		rep(i,h-1) rep(u,n) if(par[i][u]!=-1) par[i+1][u]=par[i][par[i][u]];
	}

	int lca(int u,int v)const{
		int h=par.size();

		if(dep[u]>dep[v]) swap(u,v);
		rep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];
		if(u==v) return u;

		for(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u], v=par[i][v];
		return par[0][u];
	}

	int distance(int u,int v)const{ return dep[u]+dep[v]-2*dep[lca(u,v)]; }
};

int main(){
	int n,q; scanf("%d%d",&n,&q);
	graph T(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	lowest_common_ancestor LCA(T,0);

	rep(_,q){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		puts(LCA.distance(u,v)%2==0?"Town":"Road");
	}

	return 0;
}
