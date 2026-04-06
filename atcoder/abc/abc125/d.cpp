#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,a[100000]; cin>>n;
	rep(i,n) cin>>a[i];

	lint dp[100000][2];
	dp[0][0]=a[0];
	dp[0][1]=-a[0];
	rep(i,n-1){
		dp[i+1][0]=max(dp[i][0]+a[i+1],dp[i][1]-a[i+1]);
		dp[i+1][1]=max(dp[i][0]-a[i+1],dp[i][1]+a[i+1]);
	}
	cout<<dp[n-1][0]<<endl;

	return 0;
}
