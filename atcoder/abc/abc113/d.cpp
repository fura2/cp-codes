#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1000000007;

int main(){
	int h,w,k; cin>>h>>w>>k; k--;

	int dp[101][8]={};
	dp[0][0]=1;
	rep(i,h) rep(j,w) {
		rep(S,1<<(w-1)){
			bool ok=true;
			rep(i,w-2) if((S>>i&3)==3) ok=false;
			if(!ok) continue;

			int j2=j;
			if(j>0 && S>>(j-1)&1) j2--;
			else if(S>>j&1) j2++;
			dp[i+1][j2]=(dp[i+1][j2]+dp[i][j])%MOD;
		}
	}
	cout<<dp[h][k]<<endl;

	return 0;
}
