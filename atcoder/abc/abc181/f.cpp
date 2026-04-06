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

struct edge{
	int u,v,cost;
	edge(){}
	edge(int u,int v,int cost):u(u),v(v),cost(cost){}
	bool operator<(const edge& e)const{ return cost<e.cost; }
};

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	int s=n,t=n+1;
	vector<edge> E;
	rep(i,n) for(int j=i+1;j<n;j++) {
		E.emplace_back(i,j,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	}
	rep(i,n){
		E.emplace_back(s,i,(100-y[i])*(100-y[i]));
		E.emplace_back(i,t,(y[i]+100)*(y[i]+100));
	}

	sort(E.begin(),E.end());

	union_find U(n+2);
	for(auto e:E){
		U.unite(e.u,e.v);
		if(U.is_same(s,t)){
			printf("%.9f\n",sqrt(e.cost)/2);
			break;
		}
	}

	return 0;
}
