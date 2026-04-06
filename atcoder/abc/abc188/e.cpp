#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_directed_edge(G,u,v);
	}

	vector<lint> dp(n,INF);
	rep(u,n) for(int v:G[u]) {
		dp[v]=min({dp[v],dp[u],a[u]});
	}

	lint ans=-INF;
	rep(u,n) ans=max(ans,a[u]-dp[u]);
	printf("%lld\n",ans);

	return 0;
}
