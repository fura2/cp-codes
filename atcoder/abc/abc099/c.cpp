#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;

	int dp[100001]={};
	rep(i,n+1) dp[i]=i;
	for(int a=6;a<=n;a*=6) for(int w=a;w<=n;w++) dp[w]=min(dp[w],dp[w-a]+1);
	for(int a=9;a<=n;a*=9) for(int w=a;w<=n;w++) dp[w]=min(dp[w],dp[w-a]+1);
	cout<<dp[n]<<endl;

	return 0;
}
