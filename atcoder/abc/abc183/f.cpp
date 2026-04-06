#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	int n;
	vector<int> p;
	vector<map<int,int>> f; // color -> number of vertices
public:
	union_find(int n,vector<int> color):n(n),p(n,-1),f(n){
		rep(u,n) f[u][color[u]]=1;
	}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
			for(auto [c,k]:f[v]) f[u][c]+=k;
			f[v].clear();
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
	int query(int u,int color){
		return f[find(u)][color];
	}
};

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> color(n);
	rep(u,n) scanf("%d",&color[u]), color[u]--;

	union_find U(n,color);
	rep(_,q){
		int type,a,b; scanf("%d%d%d",&type,&a,&b); a--; b--;
		if(type==1) U.unite(a,b);
		else        printf("%d\n",U.query(a,b));
	}

	return 0;
}
