#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;

vector<vector<int>> T;
vector<int> path;

bool dfs1(int u,int p){
	if(u==T.size()-1){
		path.emplace_back(u);
		return true;
	}

	for(int v:T[u]) if(v!=p) {
		if(dfs1(v,u)){
			path.emplace_back(u);
			return true;
		}
	}
	return false;
}

int dfs2(int u,int p){
	int res=1;
	for(int v:T[u]) if(v!=p) res+=dfs2(v,u);
	return res;
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	dfs1(0,-1);
	reverse(path.begin(),path.end());

	int len=path.size();
	int l=path[(len-1)/2],r=path[(len+1)/2];
	puts(dfs2(l,r)>dfs2(r,l)?"Fennec":"Snuke");

	return 0;
}
