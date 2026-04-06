#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;

int main(){
	int n,m; cin>>n>>m;
	vector<vector<int>> G(n);
	rep(i,m){
		int u,v; cin>>u>>v; u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	bool ok=false;
	rep(u,n){
		bool b1=false,b2=false;
		for(int v:G[u]){
			if(v==  0) b1=true;
			if(v==n-1) b2=true;
		}
		if(b1 && b2) ok=true;
	}
	cout<<(ok?"POSSIBLE":"IMPOSSIBLE")<<endl;

	return 0;
}
