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
	mint operator-()const{ mint m; m.x=(x==0?0:MOD-x); return m; }

	bool operator==(const mint& m)const{ return x==m.x; }
	bool operator!=(const mint& m)const{ return !((*this)==m); }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

template<class F>
pair<F,F> solve_eq(const F& a,const F& b,const F& c,const F& d,const F& e,const F& f){
	F det=a*d-b*c;
	assert(det!=F{});
	return {(d*e-b*f)/det,(-c*e+a*f)/det};
}

int main(){
	mint A,B,C; cin>>A>>B>>C;

	mint r,c; tie(r,c)=solve_eq(A,A-B,A-C,A,B-A,C-A);
	cout<<r<<' '<<c<<'\n';

	return 0;
}
