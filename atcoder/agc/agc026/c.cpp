#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	string s; cin>>n>>s;

	lint ans=0;
	rep(S,1<<n){
		string t1,t2;
		rep(i,n){
			if(S>>i&1) t1+=s[i];
			else       t2+=s[i];
		}
		reverse(t1.begin(),t1.end());
		reverse(t2.begin(),t2.end());

		int m=t1.length();
		lint dp[19][19]={}; // dp[i][j] := t1[0,i) と t2[0,j) を使って s[n,n+i+j) を作る方法の数
		dp[0][0]=1;
		rep(k,n+1){
			rep(i,k+1){
				int j=k-i;
				if(i< m  && s[n+k]==t1[i]) dp[i+1][j]+=dp[i][j];
				if(j<n-m && s[n+k]==t2[j]) dp[i][j+1]+=dp[i][j];
			}
		}
		ans+=dp[m][n-m];
	}
	cout<<ans<<'\n';

	return 0;
}
