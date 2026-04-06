#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	int n;
	vector<int> a;
public:
	union_find(int N):a(N,-1),n(N){}
	int find(int x){
		if(a[x]<0) return x;
		return a[x]=find(a[x]);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){ a[x]+=a[y]; a[y]=x; n--; }
	}
	int size(){ return n; }
	int size(int x){ return -a[find(x)]; }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);

	union_find U(n);
	rep(i,m){
		int u,v; scanf("%d%d%*d",&u,&v); u--; v--;
		U.unite(u,v);
	}

	printf("%d\n",U.size());

	return 0;
}
