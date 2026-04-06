#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;

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
	int n; scanf("%d",&n);
	vector<vector<int>> T(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	lowest_common_ancestor LCA(T);

	int q; scanf("%d",&q);
	rep(_,q){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		printf("%d\n",LCA.dist(u,v)+1);
	}

	return 0;
}
