#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<int>> G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
	}

	double dp0[600]={};
	for(int u=n-2;u>=0;u--){
		for(int v:G[u]){
			dp0[u]+=dp0[v];
		}
		dp0[u]=dp0[u]/G[u].size()+1;
	}

	double ans=1e77;
	rep(i,n){
		int j=-1;
		for(int k:G[i]){ if(j==-1 || dp0[j]<dp0[k]) j=k; }

		double dp[600]={};
		for(int u=n-2;u>=0;u--){
			int deg=0;
			for(int v:G[u]) if(!(u==i && v==j)) {
				dp[u]+=dp[v];
				deg++;
			}
			dp[u]=dp[u]/deg+1;
		}
		ans=min(ans,dp[0]);
	}
	printf("%.15f\n",ans);

	return 0;
}
