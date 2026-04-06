#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> struct edge{
	int u,v;
	T wt;
	bool operator<(const edge& e)const{ return wt<e.wt; }
};

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

class mint{
	static const int MOD=1e9+7;
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

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	int n,m;
	lint tar; scanf("%d%d%lld",&n,&m,&tar);
	vector<edge<lint>> E(m);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		E[i]=edge<lint>{u,v,c};
	}

	sort(E.begin(),E.end());

	lint mst=0;
	{
		union_find U(n);
		for(auto e:E) if(!U.is_same(e.u,e.v)) mst+=e.wt, U.unite(e.u,e.v);
	}

	int crit=0,above=0;
	for(auto e0:E){
		lint cost=e0.wt;
		union_find U(n);
		U.unite(e0.u,e0.v);
		for(auto e:E) if(!U.is_same(e.u,e.v)) cost+=e.wt, U.unite(e.u,e.v);
		if     (cost==tar) crit++;
		else if(cost>tar) above++;
	}

	if(mst==tar) cout<<(pow(mint(2),crit)-2)*pow(mint(2),above)<<'\n';
	else         cout<<(pow(mint(2),crit)-1)*pow(mint(2),above+1)<<'\n';

	return 0;
}
