#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,c[100000];
vector<vector<int>> T;

int cnt[100000];
vector<int> ans;

void dfs(int u,int p){
	if(cnt[c[u]]==0){
		ans.emplace_back(u);
	}
	cnt[c[u]]++;
	for(int v:T[u]) if(v!=p) {
		dfs(v,u);
	}
	cnt[c[u]]--;
}

int main(){
	scanf("%d",&n);
	rep(u,n) scanf("%d",&c[u]), c[u]--;
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	dfs(0,-1);

	sort(ans.begin(),ans.end());
	for(int u:ans) printf("%d\n",u+1);

	return 0;
}
