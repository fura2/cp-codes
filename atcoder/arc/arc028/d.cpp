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

int main(){
	int n,m,q,a[2000];
	scanf("%d%d%d",&n,&m,&q);
	rep(i,n) scanf("%d",&a[i]);

	mint dp1[2001]={1};
	rep(i,n){
		// *(1-x^{a_i+1})
		for(int j=m;j>=a[i]+1;j--) dp1[j]-=dp1[j-(a[i]+1)];
		// /(1-x)
		rep(j,m) dp1[j+1]+=dp1[j];
	}

	static mint dp2[2000][2001];
	rep(i,n){
		copy(dp1,dp1+m+1,dp2[i]);

		// *(1-x)
		for(int j=m;j>0;j--) dp2[i][j]-=dp2[i][j-1];
		// /(1-x^{a_i+1})
		rep(j,m-a[i]) dp2[i][j+a[i]+1]+=dp2[i][j];
	}

	rep(_,q){
		int k,c; scanf("%d%d",&k,&c); k--;
		printf("%d\n",dp2[k][m-c].to_int());
	}

	return 0;
}
