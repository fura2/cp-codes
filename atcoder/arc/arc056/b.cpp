#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

int main(){
	int n,m,s; scanf("%d%d%d",&n,&m,&s); s--;
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<int> ans;
	vector<bool> ok(n);
	union_find U(n);
	for(int u=n-1;u>=0;u--){
		ok[u]=true;
		for(int v:G[u]) if(ok[v]) U.unite(u,v);
		if(U.is_same(u,s)) ans.emplace_back(u);
	}

	reverse(ans.begin(),ans.end());
	for(int u:ans) printf("%d\n",u+1);

	return 0;
}
