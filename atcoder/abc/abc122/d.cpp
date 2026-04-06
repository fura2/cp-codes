#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1000000007;

int dp[4][4][4][1000];

int dfs(int i,int j,int k,int n){
	if((i==0 && j==1 && k==2)
	|| (i==0 && j==2 && k==1)
	|| (i==2 && j==0 && k==1)) return 0;

	if(n==0) return 1;

	if(~dp[i][j][k][n]) return dp[i][j][k][n];

	int res=0;
	(res+=dfs(j,k,0,n-1))%=MOD;
	(res+=dfs(j,k,2,n-1))%=MOD;
	(res+=dfs(j,k,3,n-1))%=MOD;
	if(!(i==0 && j==2)
	&& !(i==0 && k==2)) (res+=dfs(j,k,1,n-1))%=MOD;
	return dp[i][j][k][n]=res;
}

int main(){
	memset(dp,-1,sizeof dp);

	int n; cin>>n;

	int ans=0;
	rep(i,4) rep(j,4) rep(k,4) (ans+=dfs(i,j,k,n-3))%=MOD;
	cout<<ans<<endl;

	return 0;
}
