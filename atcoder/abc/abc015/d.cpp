#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int W,n,k; scanf("%d%d%d",&W,&n,&k);
	int a[50],b[50];
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	int dp[51][10001]={};
	rep(i,n) for(int j=k-1;j>=0;j--) rep(w,W-a[i]+1) {
		dp[j+1][w+a[i]]=max(dp[j+1][w+a[i]],dp[j][w]+b[i]);
	}

	int ans=0;
	rep(j,k+1) rep(w,W+1) ans=max(ans,dp[j][w]);
	printf("%d\n",ans);

	return 0;
}
