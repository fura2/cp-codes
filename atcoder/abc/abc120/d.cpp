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
	int size(){ return n; }
	int size(int u){ return -p[find(u)]; }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int a[100000],b[100000];
	rep(i,m) scanf("%d%d",a+i,b+i), a[i]--, b[i]--;

	lint cnt=n*(n-1LL)/2;
	vector<lint> ans(m);
	union_find U(n);
	for(int i=m-1;i>=0;i--){
		ans[i]=cnt;
		if(!U.is_same(a[i],b[i])){
			cnt-=1LL*U.size(a[i])*U.size(b[i]);
			U.unite(a[i],b[i]);
		}
	}
	rep(i,m) printf("%lld\n",ans[i]);

	return 0;
}
