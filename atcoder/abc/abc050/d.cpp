#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

lint n;
map<lint,mint> memo[62];

mint dfs(int i,lint sum){
	if(i==-1) return 1;

	if((sum<<(i+1))+2*((1LL<<(i+1))-1)<=n) return pow(mint(3),i+1);

	if(memo[i].count(sum)>0) return memo[i][sum];

	mint res=0;
	// a_i = 0, b_i = 0
	res+=dfs(i-1,sum*2);
	// a_i = 0, b_i = 1
	if(sum*2+1<=(n>>i)){
		res+=dfs(i-1,sum*2+1);
	}
	// a_i = 1, b_i = 1
	if(sum*2+2<=(n>>i)){
		res+=dfs(i-1,sum*2+2);
	}
	return memo[i][sum]=res;
}

int main(){
	cin>>n;
	cout<<dfs(61,0)<<'\n';
	return 0;
}
