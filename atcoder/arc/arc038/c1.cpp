// subtasks 1 and 2

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

vector<int> topological_order(const graph& D){
	int n=D.size();
	vector<int> deg(n);
	rep(u,n) for(int v:D[u]) deg[v]++;

	vector<int> res;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		res.emplace_back(u);
		for(int v:D[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return res;
}

vector<int> Grundy(const graph& D){
	auto ord=topological_order(D);

	int n=D.size(),m=0;
	rep(u,n) m=max(m,int(D[u].size()));

	vector<int> g(n),last(m+1,-1);
	rep(i,n){
		int u=ord[n-i-1];
		for(int v:D[u]) last[g[v]]=u;
		while(last[g[u]]==u) g[u]++;
	}
	return g;
}

int main(){
	int n; scanf("%d",&n);
	graph G(n);
	vector<int> a(n-1);
	rep(i,n-1){
		int c; scanf("%d%d",&c,&a[i]);
		rep(j,c) G[i+1].emplace_back(i-j);
	}

	vector<int> g=Grundy(G);

	int ans=0;
	rep(i,n-1) if(a[i]%2==1) ans^=g[i+1];
	puts(ans!=0?"First":"Second");

	return 0;
}
