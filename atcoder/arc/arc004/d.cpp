#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint MOD=1000000007;

lint xgcd(lint a,lint b,lint &x,lint &y){
	if(b==0){ x=1; y=0; return a; }
	lint g=xgcd(b,a%b,y,x); y-=a/b*x;
	return g;
}

lint modinv(lint a,lint m){
	lint x,y;
	if(xgcd(a,m,x,y)==1) return (x+m)%m;
	return -1;
}

map<lint,int> prime_factorize(lint a){
	map<lint,int> res;
	for(lint p=2;p*p<=a;p++) if(a%p==0) {
		int cnt=0;
		do{ a/=p; cnt++; }while(a%p==0);
		res[p]=cnt;
	}
	if(a>1) res[a]=1;
	return res;
}

lint fact[100101];

lint nCr(int n,int r){
	return fact[n]*modinv(fact[r],MOD)%MOD*modinv(fact[n-r],MOD)%MOD;
}

lint nHr(int n,int r){
	return nCr(n+r-1,r);
}

int main(){
	fact[0]=1;
	rep(i,100100) fact[i+1]=fact[i]*(i+1)%MOD;

	int n,m; cin>>n>>m;
	int sgn=n/abs(n);
	n=abs(n);

	auto pf=prime_factorize(n);

	lint ans=1;
	for(auto a:pf) ans=ans*nHr(m,a.second)%MOD;

	lint tmp=0;
	for(int i=(sgn==1?0:1);i<=m;i+=2){
		tmp=(tmp+nCr(m,i))%MOD;
	}
	ans=ans*tmp%MOD;

	cout<<ans<<endl;

	return 0;
}
