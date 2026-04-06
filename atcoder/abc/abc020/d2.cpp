// 難しかったのでもう一度解いた

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=1LL*x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

vector<long long> divisors(long long a){
	vector<long long> res;
	for(long long i=1;i*i<=a;i++) if(a%i==0) {
		res.emplace_back(i);
		if(i*i<a) res.emplace_back(a/i);
	}
	sort(res.begin(),res.end());
	return res;
}

vector<long long> prime_factors(long long a){
	vector<long long> res;
	if(a%2==0){
		do a/=2; while(a%2==0);
		res.emplace_back(2);
	}
	for(long long p=3;p*p<=a;p+=2) if(a%p==0) {
		do a/=p; while(a%p==0);
		res.emplace_back(p);
	}
	if(a>1) res.emplace_back(a);
	sort(res.begin(),res.end());
	return res;
}

int main(){
	lint n,k; cin>>n>>k;

	mint ans=0;
	for(lint d:divisors(k)){
		auto pf=prime_factors(k/d);
		int m=pf.size();
		rep(S,1<<m){
			lint q=1;
			int sgn=1;
			rep(i,m) if(S>>i&1) q*=pf[i], sgn*=-1;
			ans+=sgn*q*((n/d)/q)*((n/d)/q+1)/2;
		}
	}
	ans*=k;
	cout<<ans<<'\n';

	return 0;
}
