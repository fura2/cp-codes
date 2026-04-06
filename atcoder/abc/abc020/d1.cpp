// 最初に解いたときのコード

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint MOD=1000000007;

vector<lint> prime_factors(lint a){
	vector<lint> res;
	for(lint p=2;p*p<=a;p++) if(a%p==0) {
		do a/=p; while(a%p==0);
		res.emplace_back(p);
	}
	if(a>1) res.emplace_back(a);
	return res;
}

// Sum_{i=1,...,n, GCD(i,k)=1} i
lint f(lint n,lint k){
	vector<lint> P=prime_factors(k);
	int m=P.size();

	lint res=0;
	rep(S,1<<m){
		lint x=1;
		int pc=0;
		rep(i,m) if(S&(1<<i)) x*=P[i], pc++;
		lint tmp=(n/x)*(n/x+1)/2%MOD*x%MOD; // Sum_{i=1,...,n, x|i} i
		if(pc%2==0) res=(res+tmp)%MOD;
		else        res=(res-tmp+MOD)%MOD;
	}
	return res;
}

int main(){
	lint n,k; cin>>n>>k;

	lint res=0;
	for(lint g=1;g*g<=k;g++) if(k%g==0) {
		res=(res+f(n/g,k/g))%MOD;
		if(g*g<k) res=(res+f(n/(k/g),g))%MOD;
	}
	cout<<k*res%MOD<<endl;

	return 0;
}
