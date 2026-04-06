#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=LLONG_MAX;

using graph=vector<vector<int>>;

class strongly_connected_components{
	int idx;
	vector<int> top,id;
	const graph& G;
	graph G_rev;

	void dfs1(int u){
		id[u]=0;
		for(int v:G[u]) if(id[v]==-1) dfs1(v);
		top[idx++]=u;
	}

	void dfs2(int u){
		id[u]=idx;
		for(int v:G_rev[u]) if(id[v]==-1) dfs2(v);
	}

public:
	graph DAG;

	strongly_connected_components(const graph& G):G(G){
		int n=G.size();
		G_rev.resize(n);
		rep(u,n) for(int v:G[u]) G_rev[v].emplace_back(u);

		idx=0;
		id.assign(n,-1);
		top.resize(n);
		rep(u,n) if(id[u]==-1) dfs1(u);

		reverse(top.begin(),top.end());

		idx=0;
		id.assign(n,-1);
		for(int u:top) if(id[u]==-1) dfs2(u), idx++;

		DAG.resize(idx);
		rep(u,n) for(int v:G[u]) if(id[u]!=id[v]) DAG[id[u]].emplace_back(id[v]);
	}

	int operator[](int i)const{ return id[i]; }
};

struct point{ lint x,y; };

lint dist2(const point& p,const point& q){ return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y); }

int main(){
	int n; scanf("%d",&n);
	vector<point> P(n);
	rep(i,n) scanf("%lld%lld",&P[i].x,&P[i].y);
	int m; scanf("%d",&m);
	vector<point> Q(m);
	rep(i,m) scanf("%lld%lld",&Q[i].x,&Q[i].y);

	vector<lint> r(n,INF);
	rep(i,n) rep(j,m) r[i]=min(r[i],dist2(P[i],Q[j]));

	graph G(n);
	rep(i,n) rep(j,n) if(i!=j && dist2(P[i],P[j])<r[i]) G[i].emplace_back(j);

	strongly_connected_components SCC(G);
	int k=SCC.DAG.size();
	vector<int> deg(k);
	rep(u,k) for(int v:SCC.DAG[u]) deg[v]++;

	printf("%ld\n",count(deg.begin(),deg.end(),0));

	return 0;
}
