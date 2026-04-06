// 抽象化 rerooting の verify

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

template<class M,class F,class G>
vector<M> rerooting(const graph& T,const F& f,const G& g){
	int n=T.size();
	vector<M> dp1(n),dp2(n);

	auto dfs1=[&](auto&& dfs1,int u,int p)->void{
		for(int v:T[u]) if(v!=p) {
			dfs1(dfs1,v,u);
			dp1[u]=dp1[u]*f(dp1[v],v);
		}
		dp1[u]=g(dp1[u],u);
	};

	auto dfs2=[&](auto&& dfs2,int u,int p,const M& dp_par)->void{
		int k=T[u].size();

		vector<M> lcum(k+1),rcum(k+1);
		rep(i,k){
			int v=T[u][i];
			lcum[i+1]=rcum[i]=(v==p?f(dp_par,p):f(dp1[v],v));
		}
		rep(i,k){
			lcum[i+1]=lcum[i+1]*lcum[i];
			rcum[k-i-1]=rcum[k-i-1]*rcum[k-i];
		}

		dp2[u]=g(lcum[k],u);
		rep(i,k){
			int v=T[u][i];
			if(v!=p){
				dfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));
			}
		}
	};

	dfs1(dfs1,0,-1);
	dfs2(dfs2,0,-1,M());

	return dp2;
}

class monoid{
public:
	int sz;
	mint cnt;
	monoid():sz(0),cnt(1){}
	monoid(int sz,mint cnt):sz(sz),cnt(cnt){}
	monoid operator*(const monoid& x)const{
		return {sz+x.sz,cnt*x.cnt};
	}
};

int main(){
	int n; scanf("%d",&n);
	graph T(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	auto f=[](monoid m,int u)->monoid{
		return {m.sz,m.cnt*fact_inverse(m.sz)};
	};
	auto g=[](monoid m,int u)->monoid{
		return {m.sz+1,m.cnt*fact(m.sz)};
	};
	for(auto res:rerooting<monoid>(T,f,g)){
		printf("%d\n",res.cnt.to_int());
	}

	return 0;
}
