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
	int n,q;
	lint m; scanf("%d%lld%d",&n,&m,&q);
	vector<pair<int,int>> E1,E2;
	rep(i,q){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		if(c==0) E1.emplace_back(u,v);
		else     E2.emplace_back(u,v);
	}

	union_find U(n);
	for(auto e:E1){
		int u,v; tie(u,v)=e;
		U.unite(u,v);
	}

	map<int,int> f;
	rep(u,n) if(f.count(U.find(u))==0) f.emplace(U.find(u),f.size());

	union_find V(U.size());
	for(auto e:E2){
		int u,v; tie(u,v)=e;
		if(U.is_same(u,v)) return puts("No"),0;
		V.unite(f[U.find(u)],f[U.find(v)]);
	}

	if(U.size()==2 && V.size()==1) return puts("No"),0;

	lint k=U.size();
	lint mn,mx=k*(k-1)/2;
	if(E2.empty()) mn=k-1; // spanning tree
	else           mn=k;   // cycle

	if((n-k)+mn<=m && m<=(n-k)+mx) puts("Yes");
	else                           puts("No");

	return 0;
}
