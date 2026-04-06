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
	int s,t; scanf("%d%d",&s,&t);
	graph G(100);
	rep(i,100){
		if(i+ 1<100) G[i].emplace_back(i+ 1), G[i+ 1].emplace_back(i);
		if(i+ 5<100) G[i].emplace_back(i+ 5), G[i+ 5].emplace_back(i);
		if(i+10<100) G[i].emplace_back(i+10), G[i+10].emplace_back(i);
	}

	printf("%d\n",distance(G,s)[t]);

	return 0;
}
