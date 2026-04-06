#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=998244353;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=1LL*x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }
	mint operator-()const{ return mint(-x); }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long y,const mint& m){ return m+y; }
mint operator*(long long y,const mint& m){ return m*y; }

template<class T>
class segment_tree{
	int n;
	vector<T> dat;
	T query(int l,int r,int a,int b,int u){
		if(l<=a && b<=r) return dat[u];
		T res=0;
		int c=(a+b)/2;
		if(l<c && a<r) res=max(res,query(l,r,a,c,2*u+1));
		if(l<b && c<r) res=max(res,query(l,r,c,b,2*u+2));
		return res;
	}
public:
	segment_tree(int N){
		for(n=1;n<N;n*=2);
		dat.assign(2*n-1,0);
	}
	void update(int u,T v){
		u+=n-1;
		dat[u]=max(dat[u],v);
		while(u>0) u=(u-1)/2, dat[u]=max(dat[2*u+1],dat[2*u+2]);
	}
	T query(int l,int r){ return query(l,r,0,n,0); }
};

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),d(n);
	rep(i,n) scanf("%d%d",&x[i],&d[i]);

	{
		vector<pair<int,int>> p(n);
		rep(i,n) p[i]={x[i],d[i]};
		sort(p.begin(),p.end());
		rep(i,n) tie(x[i],d[i])=p[i];
	}

	segment_tree<int> S(n);

	vector<mint> dp(n+1);
	dp[n]=1;
	for(int i=n-1;i>=0;i--){
		int j=lower_bound(x.begin(),x.end(),x[i]+d[i])-x.begin();
		int pos=max(j,S.query(i,j));
		S.update(i,pos);
		dp[i]=dp[i+1]+dp[pos];
	}
	cout<<dp[0]<<'\n';

	return 0;
}
