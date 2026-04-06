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
	lint n; cin>>n;

	auto p=Eratosthenes_sieve(1e6).primes();
	int m=p.size();

	lint ans=0;
	rep(i,m){
		lint c=p[i];
		rep(j,i){
			lint a=p[j];
			if(a*a*a*c*c>n) break;
			for(int k=j+1;k<i;k++){
				lint b=p[k];
				if(a*a*b*c*c>n) break;
				ans++;
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}
