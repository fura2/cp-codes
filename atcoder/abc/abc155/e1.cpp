// 下の桁から順に払う金額を決めていく (お釣りが引き算で求まる)

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

string s;
int dp[1000001][2];

int dfs(int i,bool ge){
	if(i==s.length()) return ge?0:1;

	if(dp[i][ge]!=-1) return dp[i][ge];

	int res=INF,a=s[i]-'0';
	if(ge){
		rep(d,10){
			res=min(res,dfs(i+1,d>=a)+d+(10+d-a)%10);
		}
	}
	else{
		for(int d=1;d<10;d++){
			res=min(res,dfs(i+1,d>a)+d+(10+(d-1)-a)%10);
		}
		res=min(res,dfs(i+1,false)+(9-a));
	}
	return dp[i][ge]=res;
}

int main(){
	memset(dp,-1,sizeof dp);

	cin>>s;
	reverse(s.begin(),s.end());

	printf("%d\n",dfs(0,true));

	return 0;
}
