#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint MOD=1e9+7;

int main(){
	string s; cin>>s;
	int n=s.length();

	// dp[0][i] = number of A's in s[0..i)
	// dp[1][i] = number of AB's in s[0..i)
	// dp[2][i] = number of ABC's in s[0..i)
	lint dp[3][100001]={};
	int q=0;
	lint pw=1;
	rep(i,n){
		if(s[i]=='A' || s[i]=='?'){
			rep(k,3) dp[k][i+1]+=dp[k][i];
			dp[0][i+1]+=pw;
		}
		if(s[i]=='B' || s[i]=='?'){
			rep(k,3) dp[k][i+1]+=dp[k][i];
			dp[1][i+1]+=dp[0][i];
		}
		if(s[i]=='C' || s[i]=='?'){
			rep(k,3) dp[k][i+1]+=dp[k][i];
			dp[2][i+1]+=dp[1][i];
		}
		if(s[i]=='?'){
			q++;
			pw=pw*3%MOD;
		}
		rep(k,3) dp[k][i+1]%=MOD;
	}
	cout<<dp[2][n]<<endl;

	return 0;
}
