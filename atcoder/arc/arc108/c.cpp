#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

template<class T>
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
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

int n;
weighted_graph<int> T;

int color[200000];

void dfs(int u,int p){
	for(auto e:T[u]) if(e.to!=p) {
		if(e.wt==color[u]){
			color[e.to]=(e.wt+1)%n;
		}
		else{
			color[e.to]=e.wt;
		}
		dfs(e.to,u);
	}
}

int main(){
	int m; scanf("%d%d",&n,&m);
	T.resize(n);
	union_find U(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--; c--;
		if(!U.is_same(u,v)){
			add_undirected_edge(T,u,v,c);
			U.unite(u,v);
		}
	}

	dfs(0,-1);

	rep(u,n) printf("%d\n",color[u]+1);

	return 0;
}
