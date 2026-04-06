#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using tree=vector<vector<int>>;

int n;
tree T;
vector<int> sz,ans;

void dfs(int u,int p){
	sz[u]=1;
	for(int v:T[u]) if(v!=p) {
		dfs(v,u);
		sz[u]+=sz[v];
		ans[u]=max(ans[u],sz[v]);
	}
	ans[u]=max(ans[u],n-sz[u]);
}

int main(){
	scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u=i+1,v; scanf("%d",&v);
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	sz.resize(n);
	ans.resize(n);

	dfs(0,-1);

	rep(u,n) printf("%d\n",ans[u]);

	return 0;
}
