#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint MOD=1000000007;

const int N_BIN=2000;
lint nCr[N_BIN+1][N_BIN+1];
void binom(){
	rep(n,N_BIN+1) nCr[n][0]=1;
	rep(n,N_BIN) rep(r,n+1) nCr[n+1][r+1]=(nCr[n][r+1]+nCr[n][r])%MOD;
}

int h,w;
lint dp[30][901][2][2];

lint dfs(int i,int n,bool l,bool r){
	if(~dp[i][n][l][r]) return dp[i][n][l][r];

	lint res=0;
	if(i==0){
		for(int k=1;k<=n;k++){
			// don't put both left and right
			res=(res+nCr[w-2][k]*dfs(i+1,n-k,false,false))%MOD;
		}
		rep(k,n){
			// only put left
			res=(res+nCr[w-2][k]*dfs(i+1,n-k-1,true,false))%MOD;
			// only put right
			res=(res+nCr[w-2][k]*dfs(i+1,n-k-1,false,true))%MOD;
		}
		rep(k,n-1){
			// put both left and right
			res=(res+nCr[w-2][k]*dfs(i+1,n-k-2,true,true))%MOD;
		}
	}
	else if(i==h-1){
		if(n==0) res=0;
		else{
			if(l && r) res=nCr[w][n];
			else if(l) res=nCr[w-1][n-1];
			else if(r) res=nCr[w-1][n-1];
			else       res=(n>=2?nCr[w-2][n-2]:0);
		}
	}
	else{
		if(l && r){
			rep(k,n+1) res=(res+nCr[w][k]*dfs(i+1,n-k,true,true))%MOD;
		}
		else if(l){
			rep(k,n+1) res=(res+nCr[w-1][k]*dfs(i+1,n-k,true,false))%MOD;
			rep(k,n)   res=(res+nCr[w-1][k]*dfs(i+1,n-k-1,true,true))%MOD;
		}
		else if(r){
			rep(k,n+1) res=(res+nCr[w-1][k]*dfs(i+1,n-k,false,true))%MOD;
			rep(k,n)   res=(res+nCr[w-1][k]*dfs(i+1,n-k-1,true,true))%MOD;
		}
		else{
			rep(k,n+1) res=(res+nCr[w-2][k]*dfs(i+1,n-k,false,false))%MOD;
			rep(k,n)   res=(res+nCr[w-2][k]*dfs(i+1,n-k-1,true,false))%MOD;
			rep(k,n)   res=(res+nCr[w-2][k]*dfs(i+1,n-k-1,false,true))%MOD;
			rep(k,n-1) res=(res+nCr[w-2][k]*dfs(i+1,n-k-2,true,true))%MOD;
		}
	}
	return dp[i][n][l][r]=res;
}

lint f(int n){
	if(h==1 && w==1) return 1;
	else if(h==1){
		if(n<2) return 0;
		else    return nCr[w-2][n-2];
	}
	else if(w==1){
		if(n<2) return 0;
		else    return nCr[h-2][n-2];
	}
	else return dfs(0,n,false,false);
}

int main(){
	binom();

	lint r,c,d,l;
	cin>>r>>c>>h>>w>>d>>l;

	memset(dp,-1,sizeof dp);
	cout<<(r-h+1)*(c-w+1)%MOD*nCr[d+l][d]%MOD*f(d+l)%MOD<<endl;

	return 0;
}
