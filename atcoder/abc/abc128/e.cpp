#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<30;

template<class T>
class segment_tree{
	int n;
	vector<T> dat;

	void update_min(int l,int r,int a,int b,int u,T v){
		if(l<=a && b<=r){ dat[u]=min(dat[u],v); return; }
		int c=(a+b+1)/2;
		if(l<c && a<r) update_min(l,r,a,c,2*u  ,v);
		if(l<b && c<r) update_min(l,r,c,b,2*u+1,v);
	}

public:
	segment_tree(int N,T v){
		for(n=1;n<N;n*=2);
		dat.assign(2*n,v);
	}

	void update_min(int l,int r,T v){ update_min(l,r,0,n,1,v); }

	T query(int u){
		u+=n;
		T res=dat[u];
		for(u/=2;u>=1;u/=2) res=min(res,dat[u]);
		return res;
	}
};

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> x(n),l(n),r(n),d(q);
	rep(i,n){
		int s,t; scanf("%d%d%d",&s,&t,&x[i]);
		l[i]=s-x[i];
		r[i]=t-x[i];
	}
	rep(i,q) scanf("%d",&d[i]);

	vector<int> X;
	X.insert(X.end(),l.begin(),l.end());
	X.insert(X.end(),r.begin(),r.end());
	X.insert(X.end(),d.begin(),d.end());
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	int m=X.size();
	rep(i,n){
		l[i]=lower_bound(X.begin(),X.end(),l[i])-X.begin();
		r[i]=lower_bound(X.begin(),X.end(),r[i])-X.begin();
	}
	rep(i,q){
		d[i]=lower_bound(X.begin(),X.end(),d[i])-X.begin();
	}

	segment_tree<int> S(m,INF);
	rep(i,n) S.update_min(l[i],r[i],x[i]);
	rep(i,q){
		int p=S.query(d[i]);
		printf("%d\n",p<INF?p:-1);
	}

	return 0;
}
