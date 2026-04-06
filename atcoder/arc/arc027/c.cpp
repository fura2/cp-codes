#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y,n; cin>>x>>y>>n;

	int dp[301][601];
	rep(i,x+1) rep(j,x+y+1) dp[i][j]=-1;
	dp[0][0]=0;
	rep(_,n){
		int t,h; cin>>t>>h;
		for(int i=x-1;i>=0;i--) rep(j,x+y-t+1) if(~dp[i][j]) {
			dp[i+1][j+t]=max(dp[i+1][j+t],dp[i][j]+h);
		}
	}

	int ans=0;
	rep(i,x+1) rep(j,x+y+1) ans=max(ans,dp[i][j]);
	cout<<ans<<endl;

	return 0;
}
