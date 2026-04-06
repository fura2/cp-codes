#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

graph T;
vector<int> dep;

void dfs(int u,int p){
	if(p!=-1) dep[u]=dep[p]+1;
	for(int v:T[u]) if(v!=p) dfs(v,u);
}

vector<lint> wt;

void dfs2(int u,int p){
	for(int v:T[u]) if(v!=p) {
		wt[v]+=wt[u];
		dfs2(v,u);
	}
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	vector<pair<int,int>> E(n-1);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
		E[i]={u,v};
	}

	dep.resize(n);
	dfs(0,-1);

	int q; scanf("%d",&q);
	wt.resize(n);
	rep(_,q){
		int type,i;
		lint val; scanf("%d%d%lld",&type,&i,&val); i--;
		int u,v; tie(u,v)=E[i];

		if(type==2) swap(u,v);

		if(dep[u]<dep[v]){
			wt[0]+=val;
			wt[v]-=val;
		}
		else{
			wt[u]+=val;
		}
	}
	dfs2(0,-1);

	rep(u,n) printf("%lld\n",wt[u]);

	return 0;
}
