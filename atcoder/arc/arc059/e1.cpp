// はじめて解いたときのコード

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

int n,a[400],b[400];

bool vis_g[400][401];
mint memo_g[400][401];
mint g(int i,int j){ // Sum_{x_i=a_i}^{b_i} x_i^j
	if(vis_g[i][j]) return memo_g[i][j];
	vis_g[i][j]=true;

	mint res;
	for(int x=a[i];x<=b[i];x++) res+=pow(mint(x),j);
	return memo_g[i][j]=res;
}

bool vis_f[400][401];
mint memo_f[400][401];
mint f(int i,int c){
	if(i==n) return c==0?1:0;

	if(vis_f[i][c]) return memo_f[i][c];
	vis_f[i][c]=true;

	mint res;
	rep(j,c+1) res+=g(i,j)*f(i+1,c-j);
	return memo_f[i][c]=res;
}

int main(){
	int c; cin>>n>>c;
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>b[i];

	cout<<f(0,c)<<'\n';

	return 0;
}
