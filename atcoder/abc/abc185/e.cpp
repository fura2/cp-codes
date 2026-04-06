#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int m,n; scanf("%d%d",&m,&n);
	vector<int> a(m),b(n);
	rep(i,m) scanf("%d",&a[i]);
	rep(j,n) scanf("%d",&b[j]);

	vector dp(m+1,vector(n+1,INF));
	dp[0][0]=0;
	rep(i,m+1) rep(j,n+1) if(dp[i][j]<INF) {
		if(i<m) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
		if(j<n) dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
		if(i<m && j<n) dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+(a[i]==b[j]?0:1));
	}
	printf("%d\n",dp[m][n]);

	return 0;
}
