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

const long long INF=1LL<<61;

int main(){
	Eratosthenes_sieve E(51);

	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	int m=E.primes().size();
	lint ans=INF;
	rep(S,1<<m){
		lint x=1;
		rep(i,m) if(S>>i&1) x*=E.primes()[i];
		bool ok=true;
		rep(i,n) if(gcd(x,a[i])==1) {
			ok=false;
			break;
		}
		if(ok) ans=min(ans,x);
	}
	printf("%lld\n",ans);

	return 0;
}
