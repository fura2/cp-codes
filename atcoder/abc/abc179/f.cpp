#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const int INF=1<<29;

class segment_tree_dual{
	int n;
	vector<int> seg;

	void update(int l,int r,int a,int b,int u,int x){
		if(l<=a && b<=r){ seg[u]=min(seg[u],x); return; }
		int c=(a+b+1)/2;
		if(l<c && a<r) update(l,r,a,c,2*u  ,x);
		if(l<b && c<r) update(l,r,c,b,2*u+1,x);
	}

public:
	segment_tree_dual(int N){
		for(n=1;n<N;n*=2);
		seg.assign(2*n,INF);
	}

	void update(int l,int r,int x){ update(l,r,0,n,1,x); }

	int get(int u){
		u+=n;
		int res=seg[u];
		for(u/=2;u>=1;u/=2) res=min(res,seg[u]);
		return res;
	}
};

int main(){
	int n,q; scanf("%d%d",&n,&q);

	segment_tree_dual R(n),C(n);
	R.update(1,n-1,n-2);
	C.update(1,n-1,n-2);

	lint ans=(n-2LL)*(n-2LL);
	rep(_,q){
		int type,x; scanf("%d%d",&type,&x); x--;
		if(type==1){
			int val=C.get(x);
			ans-=val;
			R.update(1,val+1,x-1);
		}
		else{
			int val=R.get(x);
			ans-=val;
			C.update(1,val+1,x-1);
		}
	}
	printf("%lld\n",ans);

	return 0;
}
