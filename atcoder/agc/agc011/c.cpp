#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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
	int n,m; scanf("%d%d",&n,&m);

	union_find U(n),V(2*n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		U.unite(u,v);
		V.unite(u,n+v);
		V.unite(n+u,v);
	}

	lint c1=0,c2=0,c3=0;
	vector<bool> vis(n);
	rep(u,n){
		int r=U.find(u);
		if(!vis[r]){
			vis[r]=true;
			if     (U.size(u)==1)      c1++;
			else if(!V.is_same(u,n+u)) c2++;
			else                       c3++;
		}
	}
	printf("%lld\n",c1*n+(n-c1)*c1+c2*(2*c2+c3)+c3*(c2+c3));

	return 0;
}
