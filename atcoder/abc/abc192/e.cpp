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
void add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

const long long INF=1LL<<61;

int main(){
	int n,m,s,t; scanf("%d%d%d%d",&n,&m,&s,&t); s--; t--;

	weighted_graph<pair<lint,lint>> G(n);
	rep(i,m){
		int u,v,t,k; scanf("%d%d%d%d",&u,&v,&t,&k); u--; v--;
		add_undirected_edge(G,u,v,{t,k});
	}

	vector<lint> d(n,INF);
	d[s]=0;
	priority_queue<pair<lint,int>> Q;
	Q.emplace(0,s);
	while(!Q.empty()){
		lint d0=-Q.top().first;
		int u=Q.top().second; Q.pop();

		if(d0>d[u]) continue;

		for(auto e:G[u]){
			lint d2=d[u];
			d2=(d2+e.wt.second-1)/e.wt.second*e.wt.second;
			d2+=e.wt.first;
			if(d2<d[e.to]){
				d[e.to]=d2;
				Q.emplace(-d2,e.to);
			}
		}
	}
	printf("%lld\n",d[t]<INF?d[t]:-1);

	return 0;
}
