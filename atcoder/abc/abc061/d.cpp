#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using wgraph=vector<vector<edge<T>>>;

template<class T>
vector<T> Bellman_Ford(const wgraph<T>& G,int s){
	const T INF=numeric_limits<T>::max();

	int n=G.size();
	vector<T> d(n,INF);
	d[s]=0;
	rep(_,n-1){
		bool upd=false;
		rep(u,n) if(d[u]<INF) for(const auto& e:G[u]) {
			int v=e.to;
			if(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt, upd=true;
		}
		if(!upd) return d;
	}

	queue<int> Q;
	rep(u,n) if(d[u]<INF) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>-INF && (d[u]==-INF || d[v]>d[u]+e.wt)) d[v]=-INF, Q.emplace(v);
		}
	}
	return d;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	wgraph<lint> G(n);
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		G[u].emplace_back(v,-c);
	}

	lint ans=Bellman_Ford(G,0)[n-1];

	if(ans>-LLONG_MAX) cout<<-ans<<endl;
	else               cout<<"inf"<<endl;

	return 0;
}
