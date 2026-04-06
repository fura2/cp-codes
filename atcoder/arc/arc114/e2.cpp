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

vector<long long> enumerate_mod_inverse(int n,int mod){
	vector<long long> inv(n+1);
	if(n>0) inv[1]=1;
	for(int i=2;i<=n;i++){
		long long x=(mod+i-1)/i;
		inv[i]=x*inv[i*x%mod]%mod;
	}
	return inv;
}

int main(){
	int h,w,x1,y1,x2,y2;
	scanf("%d%d%d%d%d%d",&h,&w,&x1,&y1,&x2,&y2); x1--; y1--; x2--; y2--;

	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2);

	int a=x1,b=h-x2-1,c=y1,d=w-y2-1,e=x2-x1+y2-y1;

	int l=max({a,b,c,d});
	auto v=enumerate_mod_inverse(l+e,998244353);
	vector<mint> cum(l+e+1);
	rep(i,l+e) cum[i+1]=cum[i]+v[i+1];

	cout<<1+cum[a+e]+cum[b+e]+cum[c+e]+cum[d+e]-4*cum[e]<<'\n';

	return 0;
}
