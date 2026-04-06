#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

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
	int n,x,y; scanf("%d%d%d",&n,&x,&y); x--; y--;
	graph G(n);
	rep(i,n-1){
		G[i].emplace_back(i+1);
		G[i+1].emplace_back(i);
	}
	G[x].emplace_back(y);
	G[y].emplace_back(x);

	vector<vector<int>> d(n);
	rep(u,n) d[u]=distance(G,u);

	vector<int> ans(n);
	rep(u,n) rep(v,u) ans[d[u][v]]++;
	for(int i=1;i<n;i++) printf("%d\n",ans[i]);

	return 0;
}
