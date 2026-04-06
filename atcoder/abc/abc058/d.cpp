#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e9+7; // 998244353;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=1LL*x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=m.inverse(); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }

	mint inverse()const{
		int a=x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint f(const vector<mint>& x){
	int n=x.size();
	vector<mint> sum(n+1);
	rep(i,n) sum[i+1]=sum[i]+x[i];

	mint res=0;
	rep(i,n) res+=sum[n]-sum[i+1]-mint(n-i-1)*x[i];
	return res;
}

int main(){
	int n,m; cin>>n>>m;
	vector<mint> x(n),y(m);
	rep(i,n) cin>>x[i];
	rep(i,m) cin>>y[i];

	cout<<f(x)*f(y)<<endl;

	return 0;
}
