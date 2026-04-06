#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int a[2][100];
	rep(i,2) rep(j,n) cin>>a[i][j];

	int dp[2][101]={};
	rep(i,n){
		dp[0][i+1]=dp[0][i]+a[0][i];
		dp[1][i+1]=max(dp[1][i],dp[0][i+1])+a[1][i];
	}
	cout<<dp[1][n]<<endl;

	return 0;
}
