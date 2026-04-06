#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
vector<int> T[2000];

int dfs(int u,int p,int k){ // number of nodes in the subtree rooted at u, such that depth > k
	int res=(k<0?1:0);
	for(int v:T[u]) if(v!=p) res+=dfs(v,u,k-1);
	return res;
}

int main(){
	int k; cin>>n>>k;
	rep(i,n-1){
		int u,v; cin>>u>>v; u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	if(k==1) return cout<<n-2<<endl,0;

	int ans=n;
	rep(u,n) if(T[u].size()>1) {
		vector<int> L,R;
		for(int v:T[u]){
			L.emplace_back(dfs(v,u,k/2-1));
			R.emplace_back(dfs(v,u,(k+1)/2-1));
		}
		int mx=0;
		rep(i,L.size()) mx=max(mx,L[i]-R[i]);
		ans=min(ans,accumulate(L.begin(),L.end(),0)-mx);
	}
	cout<<ans<<endl;

	return 0;
}
