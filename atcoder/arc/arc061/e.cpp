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
	int n,m; scanf("%d%d",&n,&m);

	int k=n;
	vector<map<int,int>> f(n); // f[u][color] := (vertex id)

	vector<tuple<int,int,int>> E(m);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--; c--;
		E[i]=make_tuple(u,v,c);
		if(f[u].count(c)==0) f[u][c]=k++;
		if(f[v].count(c)==0) f[v][c]=k++;
	}

	weighted_graph<int> G(k);
	rep(u,n) for(auto p:f[u]) {
		int i=p.second;
		G[u].emplace_back(i,1);
		G[i].emplace_back(u,1);
	}
	for(auto e:E){
		int u,v,c; tie(u,v,c)=e;
		int i=f[u][c],j=f[v][c];
		G[i].emplace_back(j,0);
		G[j].emplace_back(i,0);
	}

	int res=Dijkstra(G,0)[n-1];
	printf("%d\n",res<1e8?res/2:-1);

	return 0;
}
