#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }

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
	mint operator-()const{ return mint(-x); }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	int n; scanf("%d",&n);

	int z=0;
	map<pair<lint,lint>,int> f;
	rep(i,n){
		lint a,b; scanf("%lld%lld",&a,&b);
		if(a==0 && b==0) z++;
		else{
			lint g=gcd(a,b);
			a/=g;
			b/=g;
			if(b<0 || (b==0 && a<0)) a*=-1, b*=-1;
			++f[{a,b}];
		}
	}

	mint ans=1;
	for(auto p:f){
		lint a,b; tie(a,b)=p.first;

		lint a2,b2;
		if(a>0) a2=-b, b2=a;
		else    a2=b, b2=-a;

		lint c1=p.second;
		lint c2=(f.count({a2,b2})>0?f[{a2,b2}]:0);
		if(c1>0 && c2>0 && a<=0) continue;

		ans*=pow(mint(2),c1)+pow(mint(2),c2)-1;
	}
	ans+=z-1;
	cout<<ans<<'\n';

	return 0;
}
