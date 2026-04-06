#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int W,n; scanf("%d%d",&W,&n);

	int dp[20001];
	rep(w,20001) dp[w]=INF;
	dp[0]=0;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		rep(w,20001-a) dp[w+a]=min(dp[w+a],dp[w]+b);
	}
	printf("%d\n",*min_element(dp+W,dp+20001));

	return 0;
}
