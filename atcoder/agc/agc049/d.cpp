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
	mint operator-()const{ return -x; }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=t; return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

int main(){
	int n,m; scanf("%d%d",&n,&m);

	vector<mint> f(m+1);
	f[0]=1;
	rep(i,n){
		lint k=lint(i+1)*(i+2)/2;
		// / (1-x^k)
		rep(j,m-k+1) f[j+k]+=f[j];
	}

	mint ans=0;
	rep(i,n){
		lint k=lint(n-i)*(n-i+1)/2;
		// * (1-x^k)
		for(int j=m;j>=k;j--) f[j]-=f[j-k];

		rep(h,m+1){ // a[i] = h = min_j a[j]
			lint tar=m-n*h-lint(i)*(i+1)/2;
			if(tar<0) break;
			ans+=f[tar];
		}

		k=lint(i+1)*(i+2)/2;
		// / (1-x^k)
		rep(j,m-k+1) f[j+k]+=f[j];
	}
	cout<<ans<<'\n';

	return 0;
}
