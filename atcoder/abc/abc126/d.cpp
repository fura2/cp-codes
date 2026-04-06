#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
vector<pair<int,int>> T[100000];

int color[100000];

void dfs(int u,int p,int c){
	color[u]=c;
	for(auto e:T[u]){
		int v=e.first,w=e.second;
		if(v!=p){
			dfs(v,u,(c+w)%2);
		}
	}
}

int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int u,v,w; scanf("%d%d%d",&u,&v,&w); u--; v--;
		T[u].emplace_back(v,w);
		T[v].emplace_back(u,w);
	}

	dfs(0,-1,0);

	rep(u,n) printf("%d\n",color[u]);

	return 0;
}
