#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n=0){ build(n); }
	void build(int n){
		this->n=n;
		p.assign(n,-1);
	}
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
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	int m=2e5;
	union_find U(m);
	rep(i,n/2) U.unite(a[i],a[n-i-1]);

	int ans=0;
	rep(u,m) if(U.find(u)==u) ans+=U.size(u)-1;
	printf("%d\n",ans);

	return 0;
}
