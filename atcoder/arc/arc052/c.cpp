#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

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
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&c,&u,&v);
		G[u].emplace_back(v,c);
		G[v].emplace_back(u,c);
	}

	vector<int> cnt_min(n,-1); // cnt_min[u] := (minimum number of type 1 edges from 0 to u)
	{
		weighted_graph<int> H(n);
		rep(u,n) for(auto e:G[u]){
			int v=e.to,wt=e.wt;
			H[u].emplace_back(v,wt);
		}
		cnt_min=Dijkstra(H,0);
	}

	const int K=150; // K(K+1)/2 >= N
	vector<lint> ans(n,INF);
	vector<vector<lint>> d(K,vector<lint>(n,INF)); // (type 1 edge count - offset, vertex) -> dist
	d[0][0]=0;

	priority_queue<pair<lint,pair<int,int>>> Q;
	Q.emplace(0,make_pair(0,0));
	while(!Q.empty()){
		lint d0=-Q.top().first;
		int cnt,u; tie(cnt,u)=Q.top().second;
		Q.pop();

		if(cnt-cnt_min[u]>=K || d0>d[cnt-cnt_min[u]][u]) continue;
		ans[u]=min(ans[u],d0);

		for(const auto& e:G[u]){
			int cnt2=cnt+e.wt;
			int v=e.to;
			lint cost=d0+1+(e.wt==1?cnt:0);
			if(cnt2-cnt_min[v]<K && d[cnt2-cnt_min[v]][v]>cost){
				d[cnt2-cnt_min[v]][v]=cost;
				Q.emplace(-cost,make_pair(cnt2,v));
			}
		}
	}

	rep(u,n) printf("%lld\n",ans[u]);

	return 0;
}
