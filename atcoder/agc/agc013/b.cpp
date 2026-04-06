#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
vector<int> G[100000];

bool vis[100000];
vector<int> ans;

void dfs(int u){
	vis[u]=true;
	ans.emplace_back(u);
	for(int v:G[u]) if(!vis[v]) { dfs(v); break; }
}

int main(){
	int m; scanf("%d%d",&n,&m);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	dfs(0);
	reverse(ans.begin(),ans.end());
	ans.pop_back();
	dfs(0);

	printf("%d\n",ans.size());
	for(int u:ans) printf("%d ",u+1);

	return 0;
}
