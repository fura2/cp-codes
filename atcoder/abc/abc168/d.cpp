#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

vector<int> distance(const graph& G,int s){
	const int INF=INT_MAX;
	int n=G.size();
	vector<int> d(n,INF);
	d[s]=0;
	queue<int> Q; Q.emplace(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(d[v]==INF) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}
	return d;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_edge(G,u,v);
	}

	auto d=distance(G,0);

	puts("Yes");
	for(int u=1;u<n;u++){
		for(int v:G[u]) if(d[v]+1==d[u]) {
			printf("%d\n",v+1);
			break;
		}
	}

	return 0;
}
