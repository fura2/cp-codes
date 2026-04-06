#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1000000007;

int n,k;
vector<vector<int>> G;

// c1: # of colored nodes with distance 1
// c2: # of colored nodes with distance 2
int dfs(int u,int p,int c1,int c2){
	if(k<=c1+c2) return 0;

	long long res=k-(c1+c2);
	int i=0;
	for(int v:G[u]) if(v!=p) {
		res=res*dfs(v,u,1,c1+i)%MOD;
		i++;
	}
	return res;
}

int main(){
	cin>>n>>k;
	G.resize(n);
	rep(i,n-1){
		int u,v; cin>>u>>v; u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	cout<<dfs(0,-1,0,0)<<endl;

	return 0;
}
