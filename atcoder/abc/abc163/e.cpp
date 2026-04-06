#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<pair<lint,int>> p(n);
	rep(i,n) p[i]={a[i],i};
	sort(p.rbegin(),p.rend());

	static lint dp[2001][2001];
	rep(i,n){
		int idx=p[i].second;

		rep(j,i+1){
			// a[idx] を左から j 番目に置く
			dp[j+1][i-j]=max(dp[j+1][i-j],dp[j][i-j]+a[idx]*abs(idx-j));
			// a[idx] を右から i-j 番目に置く
			dp[j][i-j+1]=max(dp[j][i-j+1],dp[j][i-j]+a[idx]*abs(n-(i-j)-1-idx));
		}
	}

	lint ans=0;
	rep(i,n+1) ans=max(ans,dp[i][n-i]);
	printf("%lld\n",ans);

	return 0;
}
