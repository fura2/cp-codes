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

mint operator+(long long y,const mint& m){ return m+y; }
mint operator*(long long y,const mint& m){ return m*y; }

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	int n,tar; scanf("%d%d",&n,&tar);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	// dp[i][j] = [x^j](1+x^a[0])*...*(1+x^a[i-1])
	vector<vector<mint>> dp(n+1,vector<mint>(tar+1));
	dp[0][0]=1;
	rep(i,n){
		dp[i+1]=dp[i];
		// * (1+x^a[i])
		for(int j=tar;j>=a[i];j--) dp[i+1][j]+=dp[i+1][j-a[i]];
	}

	vector<mint> sum(tar+1);
	rep(i,n+1) rep(j,tar+1) sum[j]+=dp[i][j];

	mint ans=sum[tar];
	rep(i,n){
		sum[0]-=1;
		// / (1+x^a[i])
		for(int j=a[i];j<=tar;j++) sum[j]-=sum[j-a[i]];
		ans+=sum[tar];
	}
	cout<<ans<<'\n';

	return 0;
}
