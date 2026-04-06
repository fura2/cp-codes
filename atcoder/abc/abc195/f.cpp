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

int main(){
	lint a,b; scanf("%lld%lld",&a,&b);

	Eratosthenes_sieve E(72);
	int m=E.primes().size();

	vector<int> X;
	for(lint x=a;x<=b;x++){
		lint mask=0;
		rep(i,m) if(x%E.primes()[i]==0) mask|=1<<i;
		X.emplace_back(mask);
	}

	lint dp[2][1<<20]={};
	int cur=0,nxt=1;
	dp[cur][0]=1;
	rep(i,b-a+1){
		// a+i を使わない
		rep(S,1<<m) dp[nxt][S]=dp[cur][S];
		// a+i を使う
		rep(S,1<<m) if((S&X[i])==0) dp[nxt][S|X[i]]+=dp[cur][S];
		swap(cur,nxt);
	}

	lint ans=0;
	rep(S,1<<m) ans+=dp[cur][S];
	printf("%lld\n",ans);

	return 0;
}
