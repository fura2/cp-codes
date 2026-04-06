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
	int n,m,R,T; scanf("%d%d%d%d",&n,&m,&R,&T);
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		G[u].emplace_back(v,c);
		G[v].emplace_back(u,c);
	}

	lint ans=0;
	rep(s,n){
		auto d=Dijkstra(G,s);
		sort(d.begin(),d.end());
		for(int u=1;u<n;u++){
			int lo=0,hi=n;
			while(hi-lo>1){
				int mi=(lo+hi)/2;
				if(R*d[u]>=T*d[mi]) lo=mi;
				else                hi=mi;
			}
			ans+=n-hi;
			if(T>R) ans--;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
