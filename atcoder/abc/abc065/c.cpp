#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint MOD=1e9+7;

int main(){
	lint fact[100001];
	fact[0]=1;
	rep(i,1e5) fact[i+1]=fact[i]*(i+1)%MOD;

	int n,m; cin>>n>>m;

	if(abs(n-m)>=2){
		cout<<0<<endl;
	}
	else if(n==m){
		cout<<fact[n]*fact[m]*2%MOD<<endl;
	}
	else{
		cout<<fact[n]*fact[m]%MOD<<endl;
	}

	return 0;
}
