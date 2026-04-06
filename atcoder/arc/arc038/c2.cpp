#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

class segment_tree{
	int n;
	vector<int> dat;
	int query(int l,int r,int a,int b,int u){
		if(l<=a && b<=r) return dat[u];
		int res=INF;
		int c=(a+b)/2;
		if(l<c && a<r) res=min(res,query(l,r,a,c,2*u+1));
		if(l<b && c<r) res=min(res,query(l,r,c,b,2*u+2));
		return res;
	}
public:
	segment_tree(int N){
		for(n=1;n<N;n*=2);
		dat.assign(2*n-1,-INF);
	}
	void update(int u,int v){
		u+=n-1;
		dat[u]=v;
		while(u>0) u=(u-1)/2, dat[u]=min(dat[2*u+1],dat[2*u+2]);
	}
	int query(int l,int r){ return query(l,r,0,n,0); }
};

int main(){
	int n; scanf("%d",&n);
	vector<int> c(n-1),a(n-1);
	rep(i,n-1) scanf("%d%d",&c[i],&a[i]);

	vector<int> g(n);
	segment_tree S(n);
	S.update(0,0);
	for(int i=1;i<n;i++){
		int lo=0,hi=n;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(S.query(0,mi)>=i-c[i-1]) lo=mi;
			else                        hi=mi;
		}
		S.update(lo,i);
		g[i]=lo;
	}

	int ans=0;
	rep(i,n-1) if(a[i]%2==1) ans^=g[i+1];
	puts(ans!=0?"First":"Second");

	return 0;
}
