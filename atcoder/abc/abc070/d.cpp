#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int n;
vector<pair<int,int>> T[100000];

lint dist[100000];

void dfs(int u,int p=-1,lint d=0){
	dist[u]=d;
	for(auto e:T[u]){
		int v=e.first,c=e.second;
		if(v!=p) dfs(v,u,d+c);
	}
}

int main(){
	cin>>n;
	rep(i,n-1){
		int u,v,c; cin>>u>>v>>c; u--; v--;
		T[u].emplace_back(v,c);
		T[v].emplace_back(u,c);
	}

	int q,k; cin>>q>>k; k--;

	dfs(k);

	rep(_,q){
		int x,y; cin>>x>>y; x--; y--;
		cout<<dist[x]+dist[y]<<endl;
	}

	return 0;
}
