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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int>> E(m);
	rep(i, m) {
		int u, v;
		scanf("%d%d", &u, &v); u--; v--;
		E[i] = {u, v};
	}

	vector<mint> dp1(1<<n, 1); // dp1[S] = (頂点集合を S に制限したときの、全域部分グラフの個数)
	rep(S, 1<<n) {
		for(auto [u,v]: E) {
			if(S>>u&1 && S>>v&1) {
				dp1[S] *= 2;
			}
		}
	}

	vector<mint> dp2(1<<n); // dp2[S] = (頂点集合を S(∋1) に制限したときの、連結部分グラフの個数)
	rep(S,1<<n) if(S&1) {
		dp2[S] = dp1[S];
		for(int T = S-1; T >= 1; T--) {
			T &= S;
			if((T&1)==0 || T==S) continue;
			dp2[S] -= dp2[T] * dp1[S&~T];
		}
	}

	rep(u, n) if (u != 0) {
		mint res;
		rep(S, 1<<n) if(S&1 && S>>u&1) {
			res += dp2[S] * dp1[((1<<n)-1)&~S];
		}
		cout << res << endl;
	}

	return 0;
}
