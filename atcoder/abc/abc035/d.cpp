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
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	const T INF=numeric_limits<T>::max();
	int n=G.size();
	vector<T> d(n,INF); d[s]=0;
	priority_queue<pair<T,int>> Q; Q.emplace(0,s);
	while(!Q.empty()){
		T d0=-Q.top().first;
		int u=Q.top().second; Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt, Q.emplace(-d[v],v);
		}
	}
	return d;
}

int main(){
	int n,m,T; scanf("%d%d%d",&n,&m,&T);
	vector<int> a(n);
	rep(u,n) scanf("%d",&a[u]);

	weighted_graph<lint> G(n),H(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		G[u].emplace_back(v,c);
		H[v].emplace_back(u,c);
	}

	auto d1=Dijkstra(G,0);
	auto d2=Dijkstra(H,0);

	lint ans=0;
	rep(u,n) if(d1[u]<LLONG_MAX && d2[u]<LLONG_MAX) ans=max(ans,a[u]*(T-d1[u]-d2[u]));
	printf("%lld\n",ans);

	return 0;
}
