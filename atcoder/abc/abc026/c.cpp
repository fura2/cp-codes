#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

int n;
graph T;

int dfs(int u){
	if(T[u].size()==0) return 1;
	int mn=1e9,mx=0;
	for(int v:T[u]){
		int tmp=dfs(v);
		mn=min(mn,tmp);
		mx=max(mx,tmp);
	}
	return mn+mx+1;
}

int main(){
	scanf("%d",&n);
	T.resize(n);
	for(int u=1;u<n;u++){
		int v; scanf("%d",&v); v--;
		T[v].emplace_back(u);
	}

	printf("%d\n",dfs(0));

	return 0;
}
