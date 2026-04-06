#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct edge{ int u,v,cost,t; };

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
	int n,m; scanf("%d%d",&n,&m);
	vector<edge> E(m);	
	rep(i,m){
		int u,v,c,t; scanf("%d%d%d%d",&u,&v,&c,&t);
		E[i]=edge{u,v,c,t};
	}

	double lo=0,hi=1e11;
	while(hi-lo>1e-3){
		double mi=(lo+hi)/2;

		sort(E.begin(),E.end(),[=](const edge& e,const edge& f){ return e.cost-mi*e.t<f.cost-mi*f.t; });

		double tmp=0;
		union_find U(n);
		for(const auto& e:E) if(e.cost-mi*e.t<0 || !U.is_same(e.u,e.v)) {
			tmp+=e.cost-mi*e.t;
			U.unite(e.u,e.v);
		}
		if(tmp<0) hi=mi; else lo=mi;
	}
	printf("%.9f\n",lo);

	return 0;
}
