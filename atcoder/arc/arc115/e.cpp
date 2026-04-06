#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
class sparse_table{
	vector<vector<T>> st;
	vector<int> h;
public:
	sparse_table(const vector<T>& a){
		int n=a.size();
		h.assign(n+1,0);
		for(int i=2;i<=n;i++) h[i]=h[i>>1]+1;
		st.resize(h[n]+1);
		st[0]=a;
		for(int i=1;i<h[n]+1;i++){
			st[i].resize(n-(1<<i)+1);
			rep(j,n-(1<<i)+1) st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
	T query(int l,int r)const{
		int i=h[r-l];
		return min(st[i][l],st[i][r-(1<<i)]);
	}
};

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

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	// O(n^2) DP
/*
	vector dp(n+1,vector(2,mint(0)));
	dp[0][0]=1;
	rep(i,n){
		lint x=INF;
		for(int j=i;j>=0;j--){
			x=min(x,a[j]);
			rep(p,2){
				dp[i+1][p]+=dp[j][p^1]*x;
			}
		}
	}
	cout<<dp[n][n%2]-dp[n][(n+1)%2]<<'\n';
*/

	vector<int> pos(n); // pos[i] = (maximum x s.t. x<i and a[x]<=a[i])
	sparse_table<lint> ST(a);
	rep(i,n){
		if(i==0 || ST.query(0,i)>a[i]){
			pos[i]=-1;
		}
		else{
			int lo=0,hi=i;
			while(hi-lo>1){
				int mi=(lo+hi)/2;
				if(ST.query(mi,i)<=a[i]) lo=mi;
				else                     hi=mi;
			}
			pos[i]=lo;
		}
	}
	rep(i,n) printf("%d ",pos[i]); puts("");

	vector dp1(n+1,vector(2,mint(0)));
	vector dp2(n+2,vector(2,mint(0))); // dp2[i+1][p] = dp1[0][p] + ... + dp1[i][p]
	dp1[0][0]=dp2[1][0]=1;
	rep(i,n){
		rep(p,2){
			dp1[i+1][p]=(dp2[i+1][p^1]-dp2[pos[i]+1][p^1])*a[i];
			if(pos[i]>=0) dp1[i+1][p]+=dp1[pos[i]+1][p];

			dp2[i+2][p]=dp2[i+1][p]+dp1[i+1][p];
		}
	}
	cout<<dp1[n][n%2]-dp1[n][(n+1)%2]<<'\n';

	return 0;
}
