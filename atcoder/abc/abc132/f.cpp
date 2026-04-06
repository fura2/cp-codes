#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

using namespace std;

const ll MOD=1000000007;

int main(){
	int n,k; cin>>n>>k;

	vector<int> C; // C := { floor(N/i) | i=1,2,...,N }
	for(int i=1;i*i<=n;i++){
		C.emplace_back(i);
		C.emplace_back(n/i);
	}
	sort(C.begin(),C.end());
	C.erase(unique(C.begin(),C.end()),C.end());
	int m=C.size();

/*
	// O(k*m^2) DP
	// dp[i][j] := ( i 個の数の並べ方で, 最後の数が (C[j-1], C[j]] に含まれるものの個数 )
	vector<vector<int>> dp(k+1,vector<int>(m));
	dp[0][0]=1;
	rep(i,k) rep(j,m) {
		ll h=C[j]-(j>0?C[j-1]:0);
		rep(l,m-j){
			dp[i+1][j]=(dp[i+1][j]+dp[i][l]*h)%MOD;
		}
	}

	ll ans=0;
	rep(j,m) ans=(ans+dp[k][j])%MOD;
	cout<<ans<<endl;
*/

	// O(k*m) DP
	// dp[i][j] := ( i 個の数の並べ方で, 最後の数が (0, C[j]] に含まれるものの個数 )
	vector<vector<int>> dp(k+1,vector<int>(m));
	rep(j,m) dp[0][j]=1;
	rep(i,k){
		dp[i+1][0]=dp[i][m-1];
		for(int j=1;j<m;j++){
			dp[i+1][j]=(dp[i+1][j-1]+1LL*dp[i][m-j-1]*(C[j]-C[j-1]))%MOD;
		}
	}

	cout<<dp[k][m-1]<<endl;

	return 0;
}
