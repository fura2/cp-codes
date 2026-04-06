#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=998244353;
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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);

// naive
/*
	mint ans=0;
	rep(i,n){
		for(int x=1;x<=m;x++){
			mint tmp=0;
			rep(j,i){
				tmp+=pow(mint(m-x),j)*(x-1)*pow(mint(m),i-j-1);
			}
			tmp+=pow(mint(m-x),i);
			ans+=tmp*pow(mint(m),n-i-1);
		}
	}
	cout<<ans<<'\n';
*/
	vector<mint> mpow(n);
	mpow[0]=1;
	rep(i,n-1) mpow[i+1]=mpow[i]*m;

	mint ans=0;
	for(int x=1;x<=m;x++){
		mint r=mint(m-x)/m;
		mint rinv=1/(1-r);
		mint rpow=1,mxpow=1;
		rep(i,n){
			mint tmp=0;
			if(i>0){
				tmp+=(1-rpow)*rinv;
				tmp*=(x-1)*mpow[i-1];
			}
			tmp+=mxpow;
			ans+=tmp*mpow[n-i-1];
			rpow*=r;
			mxpow*=m-x;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
