#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> sum(n+1);
	rep(i,n) sum[i+1]+=sum[i]+a[i];
	if(sum[n]%n!=0) return puts("-1"),0;

	int mean=sum[n]/n;

	int dp[100][101]={};
	rep(w,n) rep(l,n-w) {
		int r=l+w+1;

		if(sum[r]-sum[l]!=(w+1)*mean){
			dp[l][r]=INF;
			continue;
		}

		dp[l][r]=w;
		for(int x=l+1;x<r;x++){
			dp[l][r]=min(dp[l][r],dp[l][x]+dp[x][r]);
		}
	}
	printf("%d\n",dp[0][n]);

	return 0;
}
