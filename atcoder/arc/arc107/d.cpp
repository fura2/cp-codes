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

int main(){
	int n,k; cin>>n>>k;

	vector dp(2*n+1,vector(2*n+1,mint(0)));
	vector dp2(2*n+1,vector(2*n+1,mint(0)));
	rep(i,2*n+1){
		dp[i][0]=1;
		dp2[i][0]=1;
	}
	for(int r=1;r<=n-k;r++){
		for(int i=1;i<=2*n;i++){
			if(i+1<=r){
				dp[i][r]=dp2[2][r-1]-dp2[2*(i+1)][r-i-1];
			}
			else{
				dp[i][r]=dp2[2][r-1];
			}
			if(i+2<=2*n){
				dp2[i][r]=dp2[i+2][r-1]+dp[i][r];
			}
		}
	}
	cout<<dp[k][n-k]<<'\n';

	return 0;
}
