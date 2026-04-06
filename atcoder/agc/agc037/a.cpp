#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	string s; cin>>s;
	int n=s.length();

	int dp[200001][2]={}; // dp[i][j] = (s[0,i) について, 分割した一番右の文字列が長さ j+1 であるような最大分割数)
	for(int i=1;i<=n;i++){
		// 1 文字で分割
		dp[i][0]=dp[i-1][1]+1;
		if(i>=2 && s[i-1]!=s[i-2]) dp[i][0]=max(dp[i][0],dp[i-1][0]+1);

		// 2 文字で分割
		dp[i][1]=-INF;
		if(i>=2) dp[i][1]=dp[i-2][0]+1;
		if(i>=4 && s.substr(i-2,2)!=s.substr(i-4,2)) dp[i][1]=max(dp[i][1],dp[i-2][1]+1);
	}

	printf("%d\n",max(dp[n][0],dp[n][1]));

	return 0;
}
