/*
	Since
		y ^ x = y % x > x,
	MSB of y and x must be the same.
	Then, y - x < x, and thus
		y % x = y - x,
	which means (y & x) = x.
	Hence, the answer equals to the number of pairs (x, y) such that
		L <= x <= y <= R,
		(MSB of x) = (MSB of y),
		for all i, [i-th bit of x is 1 => that of y is also 1].
*/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;
using lint=long long;

class mint{
	static const int MOD=1e9+7; // 998244353;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint &operator+=(const mint &m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint &operator-=(const mint &m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint &operator*=(const mint &m){ x=1LL*x*m.x%MOD; return *this; }
	mint &operator/=(const mint &m){ return *this*=m.inverse(); }
	mint operator+(const mint &m)const{ return mint(*this)+=m; }
	mint operator-(const mint &m)const{ return mint(*this)-=m; }
	mint operator*(const mint &m)const{ return mint(*this)*=m; }
	mint operator/(const mint &m)const{ return mint(*this)/=m; }

	mint inverse()const{
		int a=x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend ostream &operator<<(ostream &os,const mint &m){ return os<<m.x; }
	int to_int()const{ return x; }
};

lint L,R;
bool vis[61][2][2][2];
mint memo[61][2][2][2];

mint dfs(int i,bool largerL,bool smallerR,bool msb){
	if(i==-1) return msb?1:0;

	if(vis[i][largerL][smallerR][msb]) return memo[i][largerL][smallerR][msb];
	vis[i][largerL][smallerR][msb]=true;

	mint res=0;
	if(!msb){
		if(L<(1LL<<(i+1)) && (1LL<<i)<=R){
			res+=dfs(i-1,L<(1LL<<i),(1LL<<(i+1))<=R,true); // put 1, 1
		}
		res+=dfs(i-1,false,false,false); // put 0, 0
	}
	else{
		int cnt=0;
		if(largerL || (L>>i&1)==0){
			res+=dfs(i-1,largerL,smallerR||(R>>i&1)==1,true); // put 0, 0
			cnt++;
		}
		if(smallerR || (R>>i&1)==1){
			res+=dfs(i-1,largerL||(L>>i&1)==0,smallerR,true); // put 1, 1
			cnt++;
		}
		if(cnt==2){
			res+=dfs(i-1,largerL,smallerR,true); // put 0, 1
		}
	}
	return memo[i][largerL][smallerR][msb]=res;
}

int main(){
	cin>>L>>R;
	cout<<dfs(60,false,false,false)<<endl;
	return 0;
}
