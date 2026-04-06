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

template<class T>
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<int> G(n);
	vector<pair<lint,lint>> E(m);
	rep(i,m){
		int u,v;
		lint c1,c2; scanf("%d%d%lld%lld",&u,&v,&c1,&c2); u--; v--;
		add_undirected_edge(G,u,v,i);
		E[i]={c1,c2};
	}

	vector<lint> d(n,INF);
	d[0]=0;
	priority_queue<pair<lint,int>> Q;
	Q.emplace(0,0);
	while(!Q.empty()){
		lint d0=-Q.top().first;
		int u=Q.top().second; Q.pop();
		if(d0>d[u]) continue;

		for(auto [v,i]:G[u]){
			auto [c1,c2]=E[i];

			vector<lint> T={d[u]};
			for(int dt=-2;dt<=2;dt++){
				lint t=sqrt(c2)+dt;
				if(t>=d[u]) T.emplace_back(t);
			}

			for(lint t:T){
				lint cost=(t-d[u])+c1+c2/(t+1);
				if(d[v]>d[u]+cost){
					d[v]=d[u]+cost;
					Q.emplace(-d[v],v);
				}
			}
		}
	}
	printf("%lld\n",d[n-1]<INF?d[n-1]:-1);

	return 0;
}
