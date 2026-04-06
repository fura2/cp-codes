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
	int n; scanf("%d",&n);

	union_find U(2*n);

	int q; scanf("%d",&q);
	rep(_,q){
		int type,x,y,z; scanf("%d%d%d%d",&type,&x,&y,&z); x--; y--;
		if(type==1){
			if(z%2==0){
				U.unite( x , y );
				U.unite(x+n,y+n);
			}
			else{
				U.unite( x ,y+n);
				U.unite(x+n, y );
			}
		}
		else{
			puts(U.is_same(x,y)?"YES":"NO");
		}
	}

	return 0;
}
