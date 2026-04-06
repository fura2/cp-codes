#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
class network{
	struct edge{
		int to,rev;
		T capa,flow;
		edge(int to,int rev,const T& capa,const T& flow):to(to),rev(rev),capa(capa),flow(flow){}
	};

	int s,t;
	vector<vector<edge>> G;

	vector<int> layer,now;

	bool make_layer(){
		int n=G.size();
		rep(u,n) layer[u]=(u==s?0:-1);

		queue<int> Q; Q.emplace(s);
		while(!Q.empty()){
			int u=Q.front(); Q.pop();
			for(const edge& e:G[u]) if(layer[e.to]==-1 && e.capa-e.flow>0) {
				layer[e.to]=layer[u]+1;
				if(e.to==t) return true;
				Q.emplace(e.to);
			}
		}
		return false;
	}

	T augment(int u,const T& water){
		if(u==t) return water;

		for(int& i=now[u];i<G[u].size();i++){
			edge& e=G[u][i];
			if(layer[e.to]>layer[u] && e.capa-e.flow>0){
				T w=augment(e.to,min(water,e.capa-e.flow));
				if(w>0){
					e.flow+=w;
					G[e.to][e.rev].flow-=w;
					return w;
				}
			}
		}
		return 0;
	}

public:
	network(int n,int s,int t):s(s),t(t),G(n){}

	void add_directed_edge(int u,int v,const T& capa){
		G[u].emplace_back(v,G[v].size()  ,capa,0);
		G[v].emplace_back(u,G[u].size()-1,   0,0);
	}

	void add_undirected_edge(int u,int v,const T& capa){
		G[u].emplace_back(v,G[v].size()  ,capa,0);
		G[v].emplace_back(u,G[u].size()-1,capa,0);
	}

	T maximum_flow(){
		int n=G.size();
		layer.resize(n);

		T res=0;
		while(make_layer()){
			now.assign(n,0);
			for(T water=1;water>0;res+=water) water=augment(s,numeric_limits<T>::max());
		}
		return res;
	}
};

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<lint> a(n),b(n);
	rep(u,n) scanf("%lld",&a[u]);
	rep(u,n) scanf("%lld",&b[u]);
	vector<pair<int,int>> E(m);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		E[i]={u,v};
	}

	int N=2*n+2;
	int s=N-2,t=N-1;
	network<lint> G(N,s,t);
	rep(u,n){
		// (T, S) の可能性を排除
		G.add_directed_edge(u+n,u,INF);
		// +1, delete, -1 に割り振ったときのコストを設定
		if(b[u]>=0){
			G.add_directed_edge(u+n,t,0);
			G.add_directed_edge(u,u+n,a[u]+b[u]);
			G.add_directed_edge(s,u,2*b[u]);
		}
		else{
			G.add_directed_edge(u+n,t,-2*b[u]);
			G.add_directed_edge(u,u+n,a[u]-b[u]);
			G.add_directed_edge(s,u,0);
		}
	}
	// (S, S) と (T, T) は隣接しない
	for(auto [u,v]:E){
		G.add_directed_edge(u+n,v,INF);
		G.add_directed_edge(v+n,u,INF);
	}

	lint ans=0;
	rep(u,n) ans+=abs(b[u]);
	ans-=G.maximum_flow();
	printf("%lld\n",ans);

	return 0;
}
