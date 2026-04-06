// "k 列消せる" を "n-k 列選ぶ" に言い換えると考えやすくなる

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

int main(){
	int n,k,h[301]={};
	scanf("%d%d",&n,&k);
	rep(i,n) scanf("%d",&h[i+1]);

	// dp[i][j] := ( i 列選び, 最後に選んだ列が j であるときの最適解 )
	lint dp[301][301];
	rep(i,n-k+1) rep(j,n+1) dp[i][j]=INF;
	dp[0][0]=0;
	for(int t=1;t<=n;t++){
		for(int i=n-k-1;i>=0;i--) rep(j,t) {
			dp[i+1][t]=min(dp[i+1][t],dp[i][j]+max(h[t]-h[j],0));
		}
	}

	printf("%lld\n",*min_element(dp[n-k],dp[n-k]+n+1));

	return 0;
}
