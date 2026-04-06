#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class Eratosthenes_sieve{
	vector<bool> er;
	vector<int> p;
public:
	Eratosthenes_sieve(int n):er(n+1,true){
		if(n>=0) er[0]=false;
		if(n>=1) er[1]=false;
		for(int i=2;i*i<=n;i++) if(er[i]) for(int j=i*i;j<=n;j+=i) er[j]=false;
		rep(i,n+1) if(er[i]) p.emplace_back(i);
	}

	vector<int> primes()const{ return p; }

	bool is_prime(int a)const{
		assert(a<=(int)er.size()-1);
		return a>=0 && er[a];
	}
};

bool Miller_Rabin(lint n){
	if(n<=1)   return false;
	if(n%2==0) return n==2;

	auto modpow=[](lint a,lint k,lint m){
		lint r=1;
		for(lint x=a;k>0;k>>=1){
			if(k&1) r=__int128(r)*x%m;
			x=__int128(x)*x%m;
		}
		return r;
	};

	int r=0;
	lint d=n-1;
	while(d%2==0) r++, d>>=1;

	for(lint a:{2,3,5,7,11,13,17,19,23,29,31,37}){
		if(a>=n-2) break;
		lint x=modpow(a,d,n);
		if(x==1 || x==n-1) continue;
		bool b=false;
		rep(_,r-1){
			x=__int128(x)*x%n;
			if(x==n-1){
				b=true;
				break;
			}
		}
		if(!b) return false;
	}
	return true;
}

map<lint,int> Pollard_rho(lint n){
	map<lint,int> pf;
	if(n<=1) return pf;
	if(Miller_Rabin(n)){ ++pf[n]; return pf; }

	auto divisor=[](lint n,int c)->lint{
		if(n%2==0) return 2;

		lint x=2,y=2,d=1;
		while(d==1){
			x=__int128(x)*x%n+c; if(x<0) x+=n;
			y=__int128(y)*y%n+c; if(y<0) y+=n;
			y=__int128(y)*y%n+c; if(y<0) y+=n;
			d=gcd(abs(x-y),n);
		}
		return d<n?d:-1;
	};

	lint d=-1;
	for(int c=1;d==-1;c++) d=divisor(n,c);

	for(auto [p,e]:Pollard_rho( d )) pf[p]+=e;
	for(auto [p,e]:Pollard_rho(n/d)) pf[p]+=e;
	return pf;
}

int main(){
	Eratosthenes_sieve E(3e3);

	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n){
		scanf("%lld",&a[i]);
		for(auto p:E.primes()){
			if(p*p*p>a[i]) break;
			while(a[i]%(p*p*p)==0){
				a[i]/=p*p*p;
			}
		}
	}

	map<lint,int> f;
	rep(i,n) ++f[a[i]];

	int ans=n;
	if(f.count(1)>0) ans-=f[1]-1;
	for(auto [x,c]:f) if(x>=2) {
		long double y=1;
		for(auto [p,e]:Pollard_rho(x)) rep(_,3-e) y*=p;
		if(y<=1e10 && x<y && f.count(y)>0) ans-=min(f[x],f[y]);
	}
	printf("%d\n",ans);

	return 0;
}
