#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	constexpr T INF=numeric_limits<T>::max();
	int n=G.size();
	vector<T> d(n,INF); d[s]=0;
	priority_queue<pair<T,int>,vector<pair<T,int>>,greater<>> Q;
	Q.emplace(0,s);
	while(!Q.empty()){
		T d0;
		int u; tie(d0,u)=Q.top();
		Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				Q.emplace(d[v],v);
			}
		}
	}
	return d;
}

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<lint> G(n);
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		add_directed_edge(G,u,v,c);
	}

	rep(u,n){
		auto d=Dijkstra(G,u);
		lint ans=INF;
		rep(v,n) if(d[v]<INF) for(auto e:G[v]) if(e.to==u) ans=min(ans,d[v]+e.wt);
		printf("%lld\n",ans<INF?ans:-1);
	}

	return 0;
}
