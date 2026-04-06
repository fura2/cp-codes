#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<vector<int>> G;
vector<int> color;
bool ng;

pair<int,int> dfs(int u,int c){
	color[u]=c;

	pair<int,int> res;
	(c==0?res.first:res.second)++;
	for(int v:G[u]){
		if(color[v]==c){
			ng=true;
			return {0,0};
		}
		else if(color[v]==-1){
			auto tmp=dfs(v,1-c);
			res.first+=tmp.first;
			res.second+=tmp.second;
		}
	}
	return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	static bool A[700][700];
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		A[u][v]=A[v][u]=true;
	}

	G.assign(n,vector<int>());
	rep(u,n) rep(v,n) if(u!=v && !A[u][v]) G[u].emplace_back(v);

	vector<pair<int,int>> P;
	color.assign(n,-1);
	rep(u,n) if(color[u]==-1) P.emplace_back(dfs(u,0));
	if(ng) return puts("-1"),0;

	bool dp[701]={true};
	for(auto p:P){
		bool next[701]={};
		auto update=[&](int a){ for(int w=n;w>=a;w--) next[w]|=dp[w-a]; };
		update(p.first);
		update(p.second);
		rep(w,n+1) dp[w]=next[w];
	}

	int ans=n*n;
	rep(w,n+1) if(dp[w]) ans=min(ans,w*(w-1)/2+(n-w)*(n-w-1)/2);
	printf("%d\n",ans);

	return 0;
}
