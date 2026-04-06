// DP solution (RMQ で更新を高速化)

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

template<class T>
class segment_tree{
	int n;
	vector<T> dat;
	T query(int l,int r,int a,int b,int u){
		if(l<=a && b<=r) return dat[u];
		T res=INF;
		int c=(a+b)/2;
		if(l<c && a<r) res=min(res,query(l,r,a,c,2*u+1));
		if(l<b && c<r) res=min(res,query(l,r,c,b,2*u+2));
		return res;
	}
public:
	segment_tree(int N){
		for(n=1;n<N;n*=2);
		dat.assign(2*n-1,INF);
	}
	void update(int u,T v){
		u+=n-1;
		dat[u]=min(dat[u],v);
		while(u>0) u=(u-1)/2, dat[u]=min(dat[2*u+1],dat[2*u+2]);
	}
	T query(int l,int r){ return query(l,r,0,n,0); }
};

int main(){
	int n,m;
	string s; cin>>n>>m>>s;

	segment_tree<int> dp(n+1);
	dp.update(n,0);
	for(int i=n-1;i>=0;i--) if(s[i]=='0') {
		dp.update(i,dp.query(i+1,min(i+m,n)+1)+1);
	}

	if(dp.query(0,1)==INF){ puts("-1"); return 0; }

	int c=dp.query(0,1),i=0;
	while(i<n){
		int lo=i,hi=min(i+m,n);
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(dp.query(i,mi+1)==c-1) hi=mi;
			else                      lo=mi;
		}
		printf("%d ",hi-i);
		i=hi;
		c--;
	}

	return 0;
}
