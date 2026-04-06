// O(n k^2) solution

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

int main(){
	int n,k;
	string s; cin>>n>>k>>s;

	// n0[l,r) := #{ x | l <= x < r and s[x] = 0 }
	// n1[l,r) := #{ x | l <= x < r and s[x] = 1 }
	// dp[i][mn+k][mx] := #{ s[0,i) | |n1[x,y) - n0[x,y)| <= k for all 0 <= x <= y <= i
	//                                and min S = mn
	//                                and max S = mx }
	//                    where S = { n1[x,i) - n0[x,i) | 0 <= x <= i }
	static mint dp[301][301][301];
	dp[0][k][0]=1;
	rep(i,n) for(int mn=-k;mn<=0;mn++) rep(mx,k+1) {
		if(s[i]!='1' && mn>-k) dp[i+1][mn-1+k][max(mx-1,0)]+=dp[i][mn+k][mx];
		if(s[i]!='0' && mx< k) dp[i+1][min(mn+1,0)+k][mx+1]+=dp[i][mn+k][mx];
	}

	mint ans=0;
	for(int mn=-k;mn<=0;mn++) rep(mx,k+1) ans+=dp[n][mn+k][mx];
	cout<<ans<<'\n';

	return 0;
}
