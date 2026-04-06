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
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	vector<int> X(2*n);
	rep(i,n){
		X[ i ]=a[i];
		X[n+i]=b[i];
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	rep(i,n){
		a[i]=lower_bound(X.begin(),X.end(),a[i])-X.begin();
		b[i]=lower_bound(X.begin(),X.end(),b[i])-X.begin();
	}

	int N=X.size();
	union_find U(N);
	rep(i,n) U.unite(a[i],b[i]);

	vector<int> cnt(N);
	rep(i,n) cnt[U.find(a[i])]++;
	rep(u,N) cnt[u]=min<int>(cnt[u],U.size(u));

	printf("%d\n",accumulate(cnt.begin(),cnt.end(),0));

	return 0;
}
