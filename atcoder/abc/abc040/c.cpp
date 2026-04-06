#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> dp(n,INF);
	dp[0]=0;
	rep(i,n){
		if(i+1<n) dp[i+1]=min(dp[i+1],dp[i]+abs(a[i+1]-a[i]));
		if(i+2<n) dp[i+2]=min(dp[i+2],dp[i]+abs(a[i+2]-a[i]));
	}
	printf("%d\n",dp[n-1]);

	return 0;
}
