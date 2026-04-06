// コンテスト中に書いたコード

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	int h[300];
	rep(i,n) scanf("%d",&h[i]);

	vector<int> Y(h,h+n);
	Y.emplace_back(0);
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());
	int m=Y.size();

	// dp[i][j][l] = [0,i) について, 高さを変更する操作を j 回行い, i-1 番目の高さが Y[l] であるときの最適解
	static lint dp[301][301][301];
	rep(i,n+1) rep(j,k+1) rep(l,m) dp[i][j][l]=INF;
	dp[0][k][0]=0;
	rep(i,n){
		int idx=lower_bound(Y.begin(),Y.end(),h[i])-Y.begin();
		rep(j,k+1){
			rep(l,m){
				// not change
				dp[i+1][j][idx]=min(dp[i+1][j][idx],dp[i][j][l]+max(h[i]-Y[l],0));
				// change to Y[l]
				if(j>0){
					dp[i+1][j-1][l]=min(dp[i+1][j-1][l],dp[i][j][l]);
				}
			}
		}
	}

	lint ans=INF;
	rep(j,k+1) rep(l,m) ans=min(ans,dp[n][j][l]);
	printf("%lld\n",ans);

	return 0;
}
