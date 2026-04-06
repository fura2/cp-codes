#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;

class two_edge_connected_components{
	int idx;
	vector<int> ord,low,id;
	const vector<vector<int>>& G;

	void dfs1(int u,int p){
		ord[u]=low[u]=idx++;
		bool f=true;
		for(int v:G[u]){
			if(v==p && f){ f=false; continue; }
			if(ord[v]==-1){
				dfs1(v,u);
				low[u]=min(low[u],low[v]);
			}
			else{
				low[u]=min(low[u],ord[v]);
			}
		}
	}

	void dfs2(int u,int p){
		if(p==-1 || ord[p]<low[u]){
			id[u]=idx++;
			if(p!=-1) bridge.emplace_back(minmax(p,u));
		}
		else{
			id[u]=id[p];
		}
		for(int v:G[u]) if(id[v]==-1) dfs2(v,u);
	}

public:
	vector<pair<int,int>> bridge;
	vector<vector<int>> tree;

	two_edge_connected_components(const vector<vector<int>>& G):G(G){
		int n=G.size();

		idx=0;
		ord.assign(n,-1);
		low.assign(n,-1);
		rep(u,n) if(ord[u]==-1) dfs1(u,-1);

		idx=0;
		id.assign(n,-1);
		rep(u,n) if(id[u]==-1) dfs2(u,-1);

		tree.resize(idx);
		rep(u,n) for(int v:G[u]) if(id[u]!=id[v]) tree[id[u]].emplace_back(id[v]);
	}

	int operator[](int i)const{ return id[i]; }
};

class lowest_common_ancestor{
	vector<int> dep;
	vector<vector<int>> par;
	const vector<vector<int>>& T;

	void dfs(int u,int p,int d){
		dep[u]=d;
		par[0][u]=p;
		for(int v:T[u]) if(v!=p) dfs(v,u,d+1);
	}

public:
	lowest_common_ancestor(const vector<vector<int>>& T,int root=0):T(T){
		int n=T.size(),h;
		for(h=1;(1<<h)<n;h++);

		dep.assign(n,0);
		par.assign(h,vector<int>(n,-1));

		dfs(root,-1,0);
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

	int dist(int u,int v)const{ return dep[u]+dep[v]-2*dep[lca(u,v)]; }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<int>> G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	two_edge_connected_components Te(G);
	lowest_common_ancestor LCA(Te.tree);

	int q; scanf("%d",&q);
	rep(_,q){
		int a,b,c; scanf("%d%d%d",&a,&b,&c); a--; b--; c--;
		puts(LCA.dist(Te[a],Te[c])<LCA.dist(Te[a],Te[b])+LCA.dist(Te[b],Te[c])?"NG":"OK");
	}

	return 0;
}
