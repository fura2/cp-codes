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

int main(){
	int n; scanf("%d",&n);
	weighted_graph<pair<int,int>> T(n);
	rep(i,n-1){
		int u,v,w1,w2; scanf("%d%d%d%d",&u,&v,&w1,&w2); u--; v--;
		add_undirected_edge(T,u,v,make_pair(w1,w2));
	}

	vector<int> cum1(n),cum2(n);
	auto dfs=[&](auto&& dfs,int u,int p,int cur1,int cur2)->void{
		cum1[u]=cur1;
		cum2[u]=cur2;
		for(auto e:T[u]) if(e.to!=p) {
			dfs(dfs,e.to,u,cur1^e.wt.first,cur2^e.wt.second);
		}
	};
	dfs(dfs,0,-1,0,0);

	int offset=0;
	rep(u,n) offset^=cum1[u]^cum2[u];
	rep(u,n) cum2[u]^=offset;

	sort(cum1.begin(),cum1.end());
	sort(cum2.begin(),cum2.end());
	puts(cum1==cum2?"YES":"NO");

	return 0;
}
