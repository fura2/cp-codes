// 下の桁から順にお釣りを決めていく (払う金額が足し算で求まる)

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

string s;
int dp[1000001][2];

int dfs(int i,int carry){
	if(i==s.length()) return carry;

	if(dp[i][carry]!=-1) return dp[i][carry];

	int res=INF,a=s[i]-'0';
	rep(d,10){
		res=min(res,dfs(i+1,(a+d+carry)/10)+(a+d+carry)%10+d);
	}
	return dp[i][carry]=res;
}

int main(){
	memset(dp,-1,sizeof dp);

	cin>>s;
	reverse(s.begin(),s.end());

	printf("%d\n",dfs(0,0));

	return 0;
}
