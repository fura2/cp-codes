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
lint a[100000];

lint dfs(int u,int p){
	if(p!=-1 && T[u].size()==1){
		return a[u];
	}

	vector<lint> b;
	for(int v:T[u]) if(v!=p) {
		b.emplace_back(dfs(v,u));
	}

	lint bmax=0,bsum=0;
	rep(i,b.size()){
		bmax=max(bmax,b[i]);
		bsum+=b[i];
	}

	if(bsum<a[u]){
		puts("NO");
		exit(0);
	}

	lint match;
	if(bmax<=bsum/2){
		match=bsum/2;
	}
	else{
		match=bsum-bmax;
	}
	if(match<bsum-a[u]){
		puts("NO");
		exit(0);
	}

	return bsum-2*(bsum-a[u]);
}

int main(){
	int n; scanf("%d",&n);
	rep(u,n) scanf("%lld",&a[u]);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	int root=-1;
	rep(u,n) if(T[u].size()==1) root=u;

	puts(dfs(root,-1)==a[root]?"YES":"NO");

	return 0;
}
