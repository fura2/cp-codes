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
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<pair<int,int>> E(m);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		E[i]={u,v};
	}

	vector<int> deg(n),freq(max(m+1,5));
	for(auto [u,v]:E){
		deg[u]++;
		deg[v]++;
	}
	rep(u,n) freq[deg[u]]++;

	for(int d=1;d<=m;d+=2) if(freq[d]>0) {
		puts("No");
		return 0;
	}

	if(freq[2]==n){
		puts("No");
	}
	else if(freq[2]==n-1 && freq[4]==1){
		puts("No");
	}
	else if(freq[2]==n-2 && freq[4]==2){
		int u0=find(deg.begin(),deg.end(),4)-deg.begin();
		union_find U(n);
		for(auto [u,v]:E) if(u!=u0 && v!=u0) U.unite(u,v);
		puts(U.size()==2?"No":"Yes");
	}
	else{
		puts("Yes");
	}

	return 0;
}
