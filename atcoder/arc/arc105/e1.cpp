#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

vector<vector<int>> connected_components(const graph& G){
	int n=G.size();
	vector<vector<int>> res;
	vector<bool> vis(n);
	rep(u,n) if(!vis[u]) {
		vis[u]=true;
		res.emplace_back();
		queue<int> Q; Q.emplace(u);
		while(!Q.empty()){
			int v=Q.front(); Q.pop();
			res.back().emplace_back(v);
			for(int w:G[v]) if(!vis[w]) {
				vis[w]=true;
				Q.emplace(w);
			}
		}
	}
	return res;
}

void solve(){
	lint n,m; scanf("%lld%lld",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}

	bool res;
	if(n%2==1){
		res=(n*(n-1)/2-m)&1;
	}
	else{
		lint a,b;
		for(auto C:connected_components(G)){
			for(int u:C){
				if     (u== 0 ) a=C.size();
				else if(u==n-1) b=C.size();
			}
		}
		if((a&1)!=(b&1)){
			res=true;
		}
		else{
			res=(n*(n-1)/2-a*b-m)&1;
		}
	}
	puts(res?"First":"Second");
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
