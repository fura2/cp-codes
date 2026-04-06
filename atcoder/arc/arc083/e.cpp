#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

graph T;
int x[1000];

int other[1000]; // other[u] := ( u を根とする部分木について, u と異なる色で塗られた頂点の重みの和の最小値 )

bool dfs(int u,int p){
	vector<pair<int,int>> Ch;
	int sum1=0,sum2=0;
	for(int v:T[u]) if(v!=p) {
		if(!dfs(v,u)) return false;
		Ch.emplace_back(x[v],other[v]);
		sum1+=min(x[v],other[v]);
		sum2+=max(x[v],other[v]);
	}
	if(sum1>x[u]) return false;

	int W=x[u]-sum1;
	static bool dp[5001];
	rep(w,W+1) dp[w]=false;
	dp[0]=true;
	for(auto p:Ch){
		int a=max(p.first,p.second)-min(p.first,p.second);
		for(int w=W;w>=a;w--) dp[w]|=dp[w-a];
	}
	int pos;
	rep(w,W+1) if(dp[w]) pos=w;
	other[u]=sum2-pos; // (sum1+sum2)-(sum1+pos)

	return true;
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int p; scanf("%d",&p); p--;
		T[i+1].emplace_back(p);
		T[p].emplace_back(i+1);
	}
	rep(u,n) scanf("%d",&x[u]);

	puts(dfs(0,-1)?"POSSIBLE":"IMPOSSIBLE");

	return 0;
}
