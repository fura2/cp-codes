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
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<char> G(n);
	rep(i,m){
		int u,v;
		char c; scanf("%d%d %c",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,c);
	}

	vector d(n,vector(n,INF));
	d[0][n-1]=0;
	queue<pair<int,int>> Q; Q.emplace(0,n-1);
	while(!Q.empty()){
		int u1,v1; tie(u1,v1)=Q.front();
		Q.pop();
		for(auto e:G[u1]) for(auto f:G[v1]) {
			int u2=e.to,v2=f.to;
			if(e.wt==f.wt && d[u2][v2]==INF){
				d[u2][v2]=d[u1][v1]+2;
				Q.emplace(u2,v2);
			}
		}
	}

	int ans=INF;
	rep(u,n){
		ans=min(ans,d[u][u]);
		for(auto e:G[u]){
			ans=min(ans,d[u][e.to]+1);
		}
	}
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
