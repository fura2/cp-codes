#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1000000007;

int main(){
	string s; cin>>s;
	int n=s.length();

	reverse(s.begin(),s.end());

	int dp[100001][13]={},ten=1;
	dp[0][0]=1;
	rep(i,n){
		if(s[i]=='?'){
			rep(j,13) rep(k,10) {
				dp[i+1][(j+k*ten)%13]+=dp[i][j];
				dp[i+1][(j+k*ten)%13]%=MOD;
			}
		}
		else{
			int d=s[i]-'0';
			rep(j,13){
				dp[i+1][(j+d*ten)%13]+=dp[i][j];
				dp[i+1][(j+d*ten)%13]%=MOD;
			}
		}
		ten=ten*10%13;
	}
	printf("%d\n",dp[n][5]);

	return 0;
}
