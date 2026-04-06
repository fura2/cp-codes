#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
vector<pair<int,int>> G[100000];

bool vis[100000];
int d[100000];

bool dfs(int u){
	vis[u]=true;
	for(auto e:G[u]){
		int v=e.first,c=e.second;
		if(vis[v]){
			if(d[u]+c!=d[v]) return false;
		}
		else{
			d[v]=d[u]+c;
			if(!dfs(v)) return false;
		}
	}
	return true;
}

int main(){
	int m; scanf("%d%d",&n,&m);
	rep(i,m){
		int u,v,d; scanf("%d%d%d",&u,&v,&d); u--; v--;
		G[u].emplace_back(v,d);
		G[v].emplace_back(u,-d);
	}

	rep(u,n) if(!vis[u] && !dfs(u)) { puts("No"); return 0; }
	puts("Yes");

	return 0;
}
