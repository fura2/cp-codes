#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; cin>>n;

	vector dp(n+1,vector(2,0LL));
	dp[0][0]=dp[0][1]=1;
	rep(i,n){
		string s; cin>>s;
		if(s=="AND"){
			dp[i+1][0]=dp[i][0];
			dp[i+1][1]=dp[i][0]+2*dp[i][1];
		}
		else{
			dp[i+1][0]=2*dp[i][0]+dp[i][1];
			dp[i+1][1]=dp[i][1];
		}
	}
	cout<<dp[n][0]<<'\n';

	return 0;
}
