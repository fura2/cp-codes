#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	int A[17][17];
	rep(i,n) rep(j,n) scanf("%d",&A[i][j]);

	int cost[1<<17]={};
	rep(S,1<<n) rep(i,n) if(S>>i&1) rep(j,i) if(S>>j&1) cost[S]+=A[i][j];

	int dp[1<<17];
	rep(S,1<<n) dp[S]=-INF;
	dp[0]=0;
	rep(S,1<<n){
		for(int T=S-1;T>=0;T--){
			T&=S;
			dp[S]=max(dp[S],dp[T]+cost[S&~T]+k);
		}
	}

	printf("%d\n",dp[(1<<n)-1]-cost[(1<<n)-1]);

	return 0;
}
