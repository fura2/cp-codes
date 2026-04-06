#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	vector<mint> fib(2000);
	fib[0]=fib[1]=1;
	for(int i=2;i<2000;i++) fib[i]=fib[i-1]+fib[i-2];

	int n; cin>>n;
	char c[4];
	rep(i,4) cin>>c[i];

	if(c[1]=='A'){
		if(c[0]=='A'){
			cout<<1<<'\n';
		}
		else{
			if(c[2]=='A'){
				cout<<fib[n-2]<<'\n';
			}
			else{
				cout<<(n==2?1:pow(mint(2),n-3))<<'\n';
			}
		}
	}
	else{
		if(c[3]=='B'){
			cout<<1<<'\n';
		}
		else{
			if(c[2]=='B'){
				cout<<fib[n-2]<<'\n';
			}
			else{
				cout<<(n==2?1:pow(mint(2),n-3))<<'\n';
			}
		}
	}

	return 0;
}
