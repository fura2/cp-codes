#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<lint> a(n),t(k);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,k) scanf("%lld",&t[i]);

	sort(a.begin(),a.end());

	vector<lint> b;
	{
		map<lint,int> freq;
		rep(i,n) freq[a[i]]^=1;
		rep(i,k) freq[t[i]]^=1;
		for(auto [x,c]:freq) if(c==1) b.emplace_back(x);
	}
	int m=b.size();

	if(m>n || (m-n)%2!=0){
		puts("-1");
		return 0;
	}

	vector dp(n+1,vector(m+1,INF));
	dp[0][0]=0;
	rep(i,n+1){
		rep(j,m+1){
			if(i+1<=n && j+1<=m){
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(a[i]-b[j]));
			}
			if(i+2<=n){
				dp[i+2][j]=min(dp[i+2][j],dp[i][j]+abs(a[i]-a[i+1]));
			}
		}
	}
	printf("%lld\n",dp[n][m]);

	return 0;
}
