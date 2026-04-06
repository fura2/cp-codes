#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

pair<int,pair<int,int>> tree_diameter(const vector<vector<int>>& T){
	function<pair<int,int>(int,int)> dfs=[&](int u,int p){
		int dep=0,w=u;
		for(int v:T[u]) if(v!=p) {
			auto tmp=dfs(v,u);
			tmp.first++;
			if(tmp.first>dep) tie(dep,w)=tmp;
		}
		return make_pair(dep,w);
	};
	int u=dfs(0,-1).second;
	auto res=dfs(u,-1);
	return {res.first,{u,res.second}};
}

int main(){
	int n; scanf("%d",&n);
	vector<vector<int>> T(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	auto ans=tree_diameter(T);
	printf("%d %d\n",ans.second.first+1,ans.second.second+1);

	return 0;
}
