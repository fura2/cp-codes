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
	int n; scanf("%d",&n);
	vector<int> x(n),y(n),t(n),r(n);
	rep(u,n) scanf("%d%d%d%d",&x[u],&y[u],&t[u],&r[u]);

	weighted_graph<double> G(n);
	rep(u,n) rep(v,n) if(u!=v) {
		G[u].emplace_back(v,hypot(x[u]-x[v],y[u]-y[v])/min(t[u],r[v]));
	}

	auto d=Dijkstra(G,0);

	sort(d.begin()+1,d.end());

	double ans=0;
	for(int i=1;i<n;i++) ans=max(ans,d[i]+(n-i-1));
	printf("%.9f\n",ans);

	return 0;
}
