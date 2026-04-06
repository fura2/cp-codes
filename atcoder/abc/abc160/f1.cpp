#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

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

mint fact(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		for(;k<=n;k++) memo[k]=memo[k-1]*k;
	}
	return memo[n];
}

mint fact_inverse(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		memo[n]=inverse(fact(n));
		for(int i=n;i>k;i--) memo[i-1]=memo[i]*i;
	}
	return memo[n];
}

int n;
graph T;

int sz[200000];

void dfs0(int u,int p){
	sz[u]=1;
	for(int v:T[u]) if(v!=p) {
		dfs0(v,u);
		sz[u]+=sz[v];
	}
}

mint dp1[200000],dp2[200000];

void dfs1(int u,int p){
	dp1[u]=fact(sz[u]-1);
	for(int v:T[u]) if(v!=p) {
		dfs1(v,u);
		dp1[u]*=dp1[v]*fact_inverse(sz[v]);
	}
}

void dfs2(int u,int p,mint dp_par){
	int k=T[u].size();

	vector<mint> tmp(k);
	rep(i,k){
		int v=T[u][i];
		if(v==p) tmp[i]=dp_par*fact_inverse(n-sz[u]);
		else     tmp[i]=dp1[v]*fact_inverse(sz[v]);
	}

	vector<mint> lcum(k+1),rcum(k+1);
	lcum[0]=rcum[k]=1;
	rep(i,k){
		lcum[i+1]=lcum[i]*tmp[i];
		rcum[k-i-1]=rcum[k-i]*tmp[k-i-1];
	}

	dp2[u]=fact(n-1)*lcum[k];

	rep(i,k){
		int v=T[u][i];
		if(v!=p){
			dfs2(v,u,lcum[i]*rcum[i+1]*fact(n-1-sz[v]));
		}
	}
}

int main(){
	scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	dfs0(0,-1);
	dfs1(0,-1);
	dfs2(0,-1,1);

	rep(u,n) printf("%d\n",dp2[u].to_int());

	return 0;
}
