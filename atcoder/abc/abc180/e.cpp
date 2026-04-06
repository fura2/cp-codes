#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n),z(n);
	rep(i,n) scanf("%d%d%d",&x[i],&y[i],&z[i]);

	int dp[1<<17][17];
	rep(S,1<<n) rep(i,n) dp[S][i]=INF;
	dp[1][0]=0;
	rep(S,1<<n) rep(i,n) if(S>>i&1) {
		rep(j,n) if(~S>>j&1) {
			dp[S|1<<j][j]=min(dp[S|1<<j][j],dp[S][i]+abs(x[i]-x[j])+abs(y[i]-y[j])+max(z[j]-z[i],0));
		}
	}

	int ans=INF;
	rep(i,n) if(i!=0) ans=min(ans,dp[(1<<n)-1][i]+abs(x[i]-x[0])+abs(y[i]-y[0])+max(z[0]-z[i],0));
	printf("%d\n",ans);

	return 0;
}
