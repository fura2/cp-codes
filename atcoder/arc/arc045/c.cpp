#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

weighted_graph<int> T;
vector<int> wt;

void dfs(int u,int p){
	for(auto e:T[u]){
		int v=e.to;
		if(v==p) continue;
		wt[v]^=wt[u]^e.wt;
		dfs(v,u);
	}
}

int main(){
	int n,x; scanf("%d%d",&n,&x);
	T.resize(n);
	rep(i,n-1){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		T[u].emplace_back(v,c);
		T[v].emplace_back(u,c);
	}

	wt.resize(n);
	dfs(0,-1);

	lint ans=0;
	map<int,int> f;
	rep(u,n){
		ans+=f[wt[u]^x];
		++f[wt[u]];
	}
	printf("%lld\n",ans);

	return 0;
}
