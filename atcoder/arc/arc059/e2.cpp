// Cookie Distribution (https://atcoder.jp/contests/dwacon6th-prelims/tasks/dwacon6th_prelims_c)
// を解いたときにこの問題に言及されていたが, 覚えていなかったので解き直した

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

int n,c,a[400],b[400];

mint f(int i,int k){ // f(i,k) = Sum_{x_i=a_i}^{b_i} x_i^k
	static bool memo1[400][401];
	static mint memo2[400][401];

	if(memo1[i][k]) return memo2[i][k];
	memo1[i][k]=true;

	mint res=0;
	for(int x=a[i];x<=b[i];x++) res+=pow(mint(x),k);
	return memo2[i][k]=res;
}

int main(){
	scanf("%d%d",&n,&c);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	mint dp[401][401]; // dp[i][j] = Sum_{m_0+...+m_i=j} Prod_{i=0}^{N-1} f(i,m_i)
	dp[0][0]=1;
	rep(i,n) rep(j,c+1) {
		rep(k,j+1) dp[i+1][j]+=f(i,k)*dp[i][j-k];
	}
	printf("%d\n",dp[n][c].to_int());

	return 0;
}
