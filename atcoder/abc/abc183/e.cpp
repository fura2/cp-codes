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

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector dp(h,vector(w,vector(4,mint(0))));
	dp[0][0][0]=1;
	rep(i,h) rep(j,w) if(i+j>0 && B[i][j]=='.') {
		if(i-1>=0){
			rep(k,4) dp[i][j][1]+=dp[i-1][j][k];
			dp[i][j][1]+=dp[i-1][j][1];
		}
		if(j-1>=0){
			rep(k,4) dp[i][j][2]+=dp[i][j-1][k];
			dp[i][j][2]+=dp[i][j-1][2];
		}
		if(i-1>=0 && j-1>=0){
			rep(k,4) dp[i][j][3]+=dp[i-1][j-1][k];
			dp[i][j][3]+=dp[i-1][j-1][3];
		}
	}

	mint ans=0;
	rep(k,4) ans+=dp[h-1][w-1][k];
	cout<<ans<<'\n';

	return 0;
}
