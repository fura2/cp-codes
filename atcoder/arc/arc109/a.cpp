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
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	constexpr T INF=numeric_limits<T>::max();
	int n=G.size();
	vector<T> d(n,INF); d[s]=0;
	priority_queue<pair<T,int>> Q; Q.emplace(0,s);
	while(!Q.empty()){
		T d0=-Q.top().first;
		int u=Q.top().second; Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				Q.emplace(-d[v],v);
			}
		}
	}
	return d;
}

int main(){
	int a,b,x,y; scanf("%d%d%d%d",&a,&b,&x,&y); a--; b--;

	int n=100;
	weighted_graph<int> G(2*n);
	rep(i,n){
		add_undirected_edge(G,i,n+i,x);
	}
	rep(i,n-1){
		add_undirected_edge(G,i+1,n+i,x);
		add_undirected_edge(G,i,i+1,y);
		add_undirected_edge(G,n+i,n+i+1,y);
	}

	printf("%d\n",Dijkstra(G,a)[n+b]);

	return 0;
}
