#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int n; scanf("%d",&n);
	vector<int> l(n),r(n);
	rep(i,n) scanf("%d%d",&l[i],&r[i]), l[i]--, r[i]--;

	vector memo(100,vector(100,-1));
	auto dfs=[&](auto&& dfs,int a,int b)->int{
		if(memo[a][b]!=-1) return memo[a][b];

		set<int> S;
		rep(i,n) if(a<=l[i] && r[i]<=b) {
			S.emplace(dfs(dfs,a,l[i])^dfs(dfs,r[i],b));
		}
		int g;
		for(g=0;S.count(g)>0;g++);
		return memo[a][b]=g;
	};

	puts(dfs(dfs,0,99)>0?"Alice":"Bob");
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
