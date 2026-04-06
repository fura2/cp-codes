#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

using namespace std;

const ll MOD=1000000007;

const int N_BIN=2000;
ll nCr[N_BIN+1][N_BIN+1];
void binom(){
	rep(n,N_BIN+1) nCr[n][0]=1;
	rep(n,N_BIN) rep(r,n+1) nCr[n+1][r+1]=(nCr[n][r+1]+nCr[n][r])%MOD;
}

int main(){
	binom();

	int n,k; cin>>n>>k;
	for(int i=1;i<=k;i++) cout<<nCr[n-k+1][i]*nCr[k-1][i-1]%MOD<<endl;

	return 0;
}
