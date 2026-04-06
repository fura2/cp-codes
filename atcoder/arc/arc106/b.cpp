#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<lint> a(n),b(n);
	rep(u,n) scanf("%lld",&a[u]);
	rep(u,n) scanf("%lld",&b[u]);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}

	union_find U(n);
	rep(u,n) for(int v:G[u]) U.unite(u,v);

	vector<lint> sum(n);
	rep(u,n){
		sum[U.find(u)]+=a[u];
		sum[U.find(u)]-=b[u];
	}

	puts(count(sum.begin(),sum.end(),0LL)==n?"Yes":"No");

	return 0;
}
