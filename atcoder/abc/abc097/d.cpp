#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
	int size(){ return n; }
	int size(int u){ return -p[find(u)]; }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> p(n);
	rep(i,n) scanf("%d",&p[i]), p[i]--;

	union_find U(n);
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b); a--; b--;
		U.unite(a,b);
	}

	int ans=0;
	rep(i,n) if(U.is_same(i,p[i])) ans++;
	printf("%d\n",ans);

	return 0;
}
