// O(n^4) solution

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
	mint& operator*=(const mint& m){ x=(long long)x*m.x%MOD; return *this; }
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
	string s;
	int k; cin>>s>>k;
	int n=s.length();

	k=min(k,n);

	vector<int> freq(n+1);
	{
		int cnt=0;
		rep(i,n){
			if(s[i]=='0') cnt++;
			else          freq[cnt]++;
		}
	}

	// dp[i+1][r] = (freq[i] まで見て, j 回操作して, r 個保留にしたときの答え)
	mint dp[301][301][301];
	dp[n][0][0]=1;
	for(int i=n-1;i>=0;i--){
		rep(j,k+1) rep(r,n+1) {
			if(dp[i+1][j][r].to_int()==0) continue;

			// 今見ている場所に a 個置いて, 残りは保留
			rep(a,r+1){
				dp[i][j][r-a]+=dp[i+1][j][r];
			}

			// 今見ている場所からさらに a 個保留にする
			for(int a=1;a<=freq[i];a++){
				if(j+a>n || r+a>n) break;
				dp[i][j+a][r+a]+=dp[i+1][j][r];
			}
		}
	}

	mint ans=0;
	rep(j,k+1) ans+=dp[0][j][0];
	cout<<ans<<'\n';

	return 0;
}
