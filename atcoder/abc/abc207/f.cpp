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

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int n;
graph T;

int sz[2000];
// dp[u][b][c][k] = (u を根とする部分木について,
//                   u を選ばない or 選ぶ (b=0 or 1) として,
//                   u に色が塗られてない or 塗られている (c=0 or 1) として,
//                   色が塗られていない頂点の個数が k 個になるような頂点の選び方の数)
mint dp[2000][2][2][2001],tmp[2][2001];

void dfs(int u,int p){
	sz[u]=1;
	for(int v:T[u]) if(v!=p) {
		dfs(v,u);
		sz[u]+=sz[v];
	}

	// u を選ばない, u に色が塗られない
	int m=1,cur=0,nxt=1;
	rep(k,n+1) tmp[cur][k]=0;
	tmp[cur][1]=1;
	for(int v:T[u]) if(v!=p) {
		rep(k,n+1) tmp[nxt][k]=0;

		rep(k1,m+1) rep(k2,sz[v]+1) {
			tmp[nxt][k1+k2]+=tmp[cur][k1]*(dp[v][0][0][k2]+dp[v][0][1][k2]);
		}

		m+=sz[v];
		swap(cur,nxt);
	}
	rep(k,m+1) dp[u][0][0][k]=tmp[cur][k];

	// u を選ばない, u に色が塗られる
	m=1; cur=0; nxt=1;
	rep(k,n+1) tmp[cur][k]=0;
	tmp[cur][1]=1;
	for(int v:T[u]) if(v!=p) {
		rep(k,n+1) tmp[nxt][k]=0;

		rep(k1,m+1) rep(k2,sz[v]+1) {
			tmp[nxt][k1+k2]+=tmp[cur][k1]*(dp[v][0][0][k2]+dp[v][0][1][k2]+dp[v][1][1][k2]);
		}

		m+=sz[v];
		swap(cur,nxt);
	}
	for(int k=1;k<=m;k++) dp[u][0][1][k-1]=tmp[cur][k]-dp[u][0][0][k];

	// u を選ぶ, u に色が塗られる
	m=1; cur=0; nxt=1;
	rep(k,n+1) tmp[cur][k]=0;
	tmp[cur][0]=1;
	for(int v:T[u]) if(v!=p) {
		rep(k,n+1) tmp[nxt][k]=0;

		rep(k1,m+1) rep(k2,sz[v]+1) {
			if(k2<sz[v]) tmp[nxt][k1+k2]+=tmp[cur][k1]*dp[v][0][0][k2+1];
			tmp[nxt][k1+k2]+=tmp[cur][k1]*(dp[v][0][1][k2]+dp[v][1][1][k2]);
		}

		m+=sz[v];
		swap(cur,nxt);
	}
	rep(k,m+1) dp[u][1][1][k]=tmp[cur][k];
}

int main(){
	scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	dfs(0,-1);

	rep(k,n+1) cout<<dp[0][0][0][n-k]+dp[0][0][1][n-k]+dp[0][1][1][n-k]<<'\n';

	return 0;
}
