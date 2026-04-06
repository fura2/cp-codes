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
	int x,y; scanf("%d%d",&x,&y);

	map<int,int> f;
	f[ x]=0;
	f[-x]=1;
	f[ y]=2;
	f[-y]=3;
	weighted_graph<lint> G(4);
	G[f[ x]].emplace_back(f[-x],1);
	G[f[-x]].emplace_back(f[ x],1);
	G[f[ y]].emplace_back(f[-y],1);
	G[f[-y]].emplace_back(f[ y],1);
	for(int a:{x,-x,y,-y}) for(int b:{x,-x,y,-y}) if(a<b) {
		G[f[a]].emplace_back(f[b],b-a);
	}
	printf("%lld\n",Dijkstra(G,f[x])[f[y]]);

	return 0;
}
