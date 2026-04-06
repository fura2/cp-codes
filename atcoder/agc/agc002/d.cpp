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
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m),b(m);
	rep(i,m){
		scanf("%d%d",&a[i],&b[i]);
		a[i]--; b[i]--;
	}

	int q; scanf("%d",&q);
	vector<int> x(q),y(q),z(q);
	rep(i,q){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		x[i]--; y[i]--;
	}

	// parallel binary search
	vector<int> lo(q),hi(q,m);
	rep(_,17){
		vector<int> mi(q);
		vector<vector<int>> event(m);
		rep(i,q){
			mi[i]=(lo[i]+hi[i])/2;
			event[mi[i]].emplace_back(i);
		}

		union_find U(n);
		rep(i,m){
			for(int e:event[i]){
				int u=U.find(x[e]),v=U.find(y[e]);

				int sz;
				if(u==v) sz=U.size(u);
				else     sz=U.size(u)+U.size(v);

				if(sz<z[e]) lo[e]=mi[e];
				else        hi[e]=mi[e];
			}
			U.unite(a[i],b[i]);
		}
	}

	rep(i,q) printf("%d\n",hi[i]);

	return 0;
}
