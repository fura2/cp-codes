#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=1LL*x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=m.inverse(); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }

	mint inverse()const{
		int a=x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int s,t; scanf("%d%d",&s,&t); s--; t--;
	vector<vector<pair<int,lint>>> G(n);
	rep(i,m){
		int u,v;
		lint d; scanf("%d%d%lld",&u,&v,&d); u--; v--;
		G[u].emplace_back(v,d);
		G[v].emplace_back(u,d);
	}

	auto Dijkstra=[&](auto& d,auto& dp,int s){
		rep(u,n){
			d[u]=INF;
			dp[u]=0;
		}
		d[s]=0;
		dp[s]=1;

		priority_queue<pair<lint,int>> Q; Q.emplace(0,s);
		while(!Q.empty()){
			lint d0=-Q.top().first;
			int u=Q.top().second;
			Q.pop();

			if(d0>d[u]) continue;

			for(const auto& e:G[u]){
				int v=e.first;
				lint cost=e.second;
				if(d[v]>d[u]+cost){
					d[v]=d[u]+cost;
					dp[v]=dp[u];
					Q.emplace(-d[v],v);
				}
				else if(d[v]==d[u]+cost){
					dp[v]+=dp[u];
				}
			}
		}
	};
	vector<lint> d1(n),d2(n);
	vector<mint> dp1(n),dp2(n);
	Dijkstra(d1,dp1,s);
	Dijkstra(d2,dp2,t);

	mint ans=dp1[t]*dp2[s];
	rep(u,n) if(d1[u]+d2[u]==d1[t] && d1[u]==d2[u]) {
		ans-=(dp1[u]*dp2[u])*(dp2[u]*dp1[u]);
	}
	rep(u,n) for(const auto& e:G[u]) {
		int v=e.first;
		lint cost=e.second;
		if(d1[u]+cost+d2[v]==d1[t]){ // u-v belongs to the shortest path DAG
			if(d1[u]<d2[v]+cost && d2[v]<d1[u]+cost){ // (d1[u], d1[u]+cost) intersects (d2[v], d2[v]+cost)
				ans-=(dp1[u]*dp2[v])*(dp2[v]*dp1[u]);
			}
		}
	}
	printf("%d\n",ans.to_int());

	return 0;
}
