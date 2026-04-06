#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

graph T;
vector<int> val;

pair<int,bool> dfs(int u,int p){
	int res1=0;
	bool res2=(val[u]==1);
	for(int v:T[u]) if(v!=p) {
		auto tmp=dfs(v,u);
		if(tmp.second){
			res1+=tmp.first+2;
			res2=true;
		}
	}
	return {res1,res2};
}

int main(){
	int n,root; scanf("%d%d",&n,&root); root--;
	T.resize(n);
	val.resize(n);
	rep(u,n) scanf("%d",&val[u]);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	printf("%d\n",dfs(root,-1).first);

	return 0;
}
