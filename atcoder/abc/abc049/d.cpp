#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	vector<int> a;
public:
	union_find(int n):a(n,-1){}
	int find(int x){
		if(a[x]<0) return x;
		return a[x]=find(a[x]);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){ a[x]+=a[y]; a[y]=x; }
	}
	int size(int x){ return -a[find(x)]; }
};

int main(){
	int n,k,l; scanf("%d%d%d",&n,&k,&l);

	union_find U1(n);
	rep(i,k){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		U1.unite(u,v);
	}

	union_find U2(n);
	rep(i,l){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		U2.unite(u,v);
	}

	int m1=0;
	map<int,int> f1;
	vector<int> id1(n);
	rep(u,n){
		int p=U1.find(u);
		if(f1.count(p)==0) f1[p]=m1++;
		id1[u]=f1[p];
	}

	int m2=0;
	map<int,int> f2;
	vector<int> id2(n);
	rep(u,n){
		int p=U2.find(u);
		if(f2.count(p)==0) f2[p]=m2++;
		id2[u]=f2[p];
	}

	union_find W(n);
	map<pair<int,int>,int> g; // representative
	rep(u,n){
		pair<int,int> a(id1[u],id2[u]);
		if(g.count(a)==0) g[a]=u;
		else              W.unite(u,g[a]);
	}
	rep(u,n) printf("%d ",W.size(u));

	return 0;
}
