#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,a[3]; scanf("%d",&n);
	rep(i,3) scanf("%d",&a[i]);

	vector<int> dp(301,INF);
	dp[n]=0;
	rep(i,3) dp[a[i]]=-1;

	for(int i=n;i>0;i--) if(dp[i]!=-1) {
		for(int d=1;d<=3;d++) if(i-d>=0 && dp[i-d]!=-1) {
			dp[i-d]=min(dp[i-d],dp[i]+1);
		}
	}

	puts(dp[0]<=100?"YES":"NO");

	return 0;
}
