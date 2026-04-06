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

mint operator*(long long y,const mint& m){ return m*y; }

int main(){
	int n,k; scanf("%d%d",&n,&k);

	// dp[i][j][s] := 左の頂点 {1,2,...,i} と右の頂点 {1,2,...,i} に対して,
	//                j 組がマッチング済みで, "その時点で確定したスコア" が s であるような場合の数
	static mint dp[51][51][2501];
	dp[0][0][0]=1;
	rep(i,n) rep(j,i+1) rep(s,k+1) {
		int s2;
		// 左の i+1 と右の i+1 をマッチング
		s2=s+2*(i-j);
		if(s2<=k) dp[i+1][j+1][s2]+=dp[i][j][s];
		// 左の i+1 も右の i+1 も保留
		s2=s+2*(i-j+1);
		if(s2<=k) dp[i+1][j][s2]+=dp[i][j][s];
		// 片方の i+1 をもう片方の保留にしていた頂点とマッチング, 残った i+1 は保留
		s2=s+2*(i-j);
		if(s2<=k) dp[i+1][j+1][s2]+=2*(i-j)*dp[i][j][s];
		// 左の i+1 を右の保留にしていた頂点とマッチング, 右の i+1 を右の保留にしていた頂点とマッチング
		s2=s+2*(i-j-1);
		if(s2<=k && j<i) dp[i+1][j+2][s2]+=(i-j)*(i-j)*dp[i][j][s];
	}
	printf("%d\n",dp[n][n][k].to_int());

	return 0;
}
