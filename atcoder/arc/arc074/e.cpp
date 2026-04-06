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

mint operator+(long long y,const mint& m){ return m+y; }
mint operator*(long long y,const mint& m){ return m*y; }

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<pair<int,int>> Ev[301];
	rep(i,m){
		int l,r,c; scanf("%d%d%d",&l,&r,&c); l--;
		Ev[r].emplace_back(l,c);
	}

	// dp[i][j][k] = (最も右にある赤, 緑, 青マスがそれぞれ i, j, k マス目 (1-indexed) であるような塗り方の数)
	static mint dp[301][301][301];
	dp[0][0][0]=1;
	rep(i,n) rep(j,n) rep(k,n) {
		int next=max({i,j,k})+1;
		dp[next][j][k]+=dp[i][j][k];
		dp[i][next][k]+=dp[i][j][k];
		dp[i][j][next]+=dp[i][j][k];

		for(auto p:Ev[next]){
			int l,c; tie(l,c)=p;
			int cnt;
			cnt=1;
			if(j>=l+1) cnt++;
			if(k>=l+1) cnt++;
			if(cnt!=c) dp[next][j][k]=0;
			cnt=1;
			if(i>=l+1) cnt++;
			if(k>=l+1) cnt++;
			if(cnt!=c) dp[i][next][k]=0;
			cnt=1;
			if(i>=l+1) cnt++;
			if(j>=l+1) cnt++;
			if(cnt!=c) dp[i][j][next]=0;
		}
	}

	mint ans=0;
	rep(j,n) rep(k,n) ans+=dp[n][j][k];
	rep(i,n) rep(k,n) ans+=dp[i][n][k];
	rep(i,n) rep(j,n) ans+=dp[i][j][n];
	cout<<ans<<'\n';

	return 0;
}
