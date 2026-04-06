#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

vector<int> topological_order(const graph& D){
	int n=D.size();
	vector<int> deg(n);
	rep(u,n) for(int v:D[u]) deg[v]++;

	vector<int> res;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		res.emplace_back(u);
		for(int v:D[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return res;
}

vector<int> Grundy(const graph& D){
	auto ord=topological_order(D);

	int n=D.size(),m=0;
	rep(u,n) m=max(m,(int)D[u].size());

	vector<int> g(n),last(m+1,-1);
	rep(i,n){
		int u=ord[n-i-1];
		for(int v:D[u]) last[g[v]]=u;
		while(last[g[u]]==u) g[u]++;
	}
	return g;
}

int main(){
	int n; scanf("%d",&n);
	vector<graph> G(3,graph(n));
	rep(i,3){
		int m; scanf("%d",&m);
		rep(j,m){
			int u,v; scanf("%d%d",&u,&v); u--; v--;
			if(u>v) swap(u,v);
			G[i][u].emplace_back(v);
		}
	}

	vector<vector<int>> g(3);
	rep(i,3) g[i]=Grundy(G[i]);

	int g_max=0;
	rep(i,3) rep(u,n) g_max=max(g_max,g[i][u]);

	vector<vector<mint>> wt(3,vector<mint>(g_max+1));
	rep(i,3) rep(u,n) wt[i][g[i][u]]+=pow(mint(10),18*(u+1));

	mint ans=0;
	rep(g0,g_max+1) rep(g1,g_max+1) {
		int g2=g0^g1;
		if(g2>g_max) continue;
		ans+=wt[0][g0]*wt[1][g1]*wt[2][g2];
	}
	cout<<ans<<'\n';

	return 0;
}
