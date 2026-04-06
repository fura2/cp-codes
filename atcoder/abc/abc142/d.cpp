#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

using namespace std;

ll gcd(ll a,ll b){ return b?gcd(b,a%b):a; }

map<ll,int> prime_factorize(ll a){
	map<ll,int> res;
	for(ll p=2;p*p<=a;p++) if(a%p==0) {
		int cnt=0;
		do{ a/=p; cnt++; }while(a%p==0);
		res[p]=cnt;
	}
	if(a>1) res[a]=1;
	return res;
}

int main(){
	ll a,b; cin>>a>>b;

	auto pf=prime_factorize(gcd(a,b));
	cout<<pf.size()+1<<endl;

	return 0;
}
