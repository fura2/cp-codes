#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> h(n);
	rep(u,n) scanf("%d",&h[u]);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	int ans=0;
	rep(u,n){
		bool ok=true;
		for(int v:G[u]) if(h[u]<=h[v]) ok=false;
		if(ok) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
