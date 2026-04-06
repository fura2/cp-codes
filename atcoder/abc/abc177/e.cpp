#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

Eratosthenes_sieve E(1e6);

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int g=a[0];
	rep(i,n-1) g=gcd(g,a[i+1]);
	if(g>=2){
		puts("not coprime");
		return 0;
	}

	vector<int> freq(1e6+1);
	rep(i,n) freq[a[i]]++;
	for(int p:E.primes()){
		int cnt=0;
		for(int x=p;x<=1e6;x+=p){
			cnt+=freq[x];
		}
		if(cnt>=2){
			puts("setwise coprime");
			return 0;
		}
	}
	puts("pairwise coprime");

	return 0;
}
