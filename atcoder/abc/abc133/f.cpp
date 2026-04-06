#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct edge{ int u,v,d; };

const int V_MAX=100000,LG_V_MAX=17;

struct LCA_solver{
	int par[LG_V_MAX][V_MAX],dep[V_MAX];

	void build(int n,const vector<vector<edge>> &T,int root=0){
		struct info{ int u,pre,d; };
		static info S[V_MAX];
		int head=0,tail=0;
		S[tail++]=(info){root,-1,0};
		while(head<tail){
			int u=S[head].u,pre=S[head].pre,d=S[head].d; head++;
			par[0][u]=pre;
			dep[u]=d;
			for(edge e:T[u]) if(e.v!=pre) S[tail++]=(info){e.v,u,d+1};
		}

		rep(i,LG_V_MAX-1) rep(u,n) par[i+1][u]=(par[i][u]==-1?-1:par[i][par[i][u]]);
	}

	int lca(int u,int v)const{
		if(dep[u]>dep[v]) swap(u,v);
		rep(i,LG_V_MAX) if((dep[v]-dep[u])>>i&1) v=par[i][v];
		if(u==v) return u;

		for(int i=LG_V_MAX-1;i>=0;i--){
			if(par[i][u]!=par[i][v]){
				u=par[i][u];
				v=par[i][v];
			}
		}
		return par[0][u];
	}
};

pair<int,int> &operator+=(pair<int,int> &a,const pair<int,int> &b){
	a.first+=b.first;
	a.second+=b.second;
	return a;
}

pair<int,int> operator+(const pair<int,int> &a,const pair<int,int> &b){
	return make_pair(a.first+b.first,a.second+b.second);
}

pair<int,int> operator-(const pair<int,int> &a,const pair<int,int> &b){
	return make_pair(a.first-b.first,a.second-b.second);
}

const int N_MAX=2*V_MAX;

template<class T>
class Fenwick_tree{
	int n;
	T a[N_MAX];

public:
	void build(int n){
		this->n=n;
		rep(i,n) a[i]=T();
	}

	void add(int i,T v){
		for(;i<n;i|=i+1) a[i]+=v;
	}

	T sum(int i,int j){
		if(i==0){
			T s=T();
			for(;j>=0;j=(j&(j+1))-1) s+=a[j];
			return s;
		}
		return sum(0,j)-sum(0,i-1);
	}
};

int n;
vector<vector<edge>> T;

// Euler tour technique
int idx;
vector<int> down,up;
Fenwick_tree<pair<int,int>> F;

void dfs(int u,int p){
	for(edge e:T[u]) if(e.v!=p) {
		F.add(idx,make_pair(e.d,0));
		down[e.v]=idx++;
		dfs(e.v,u);
		F.add(idx,make_pair(-e.d,0));
		up[e.v]=idx++;
	}
}

struct query{ int u,v,d,id; };

int main(){
	int q; scanf("%d%d",&n,&q);
	T.resize(n);
	vector<vector<edge>> E(n-1); // E[c] := set of edges of color c
	rep(i,n-1){
		int u,v,c,d; scanf("%d%d%d%d",&u,&v,&c,&d); u--; v--; c--;
		T[u].emplace_back(edge{u,v,d});
		T[v].emplace_back(edge{v,u,d});
		E[c].emplace_back(edge{u,v,d});
	}

	LCA_solver L;
	L.build(n,T);

	F.build(2*n-2);
	down.resize(n);
	up  .resize(n);
	down[0]=-1;
	dfs(0,-1);

	vector<vector<query>> Q(n-1); // Q[c] := set of queries of color c
	rep(i,q){
		int c,d,u,v; scanf("%d%d%d%d",&c,&d,&u,&v); u--; v--; c--;
		Q[c].emplace_back(query{u,v,d,i});
	}

	vector<int> ans(q);
	rep(c,n-1) if(!Q[c].empty()) {
		for(edge e:E[c]){
			int u=e.u,v=e.v,d=e.d;
			if(L.dep[u]>L.dep[v]) swap(u,v);
			F.add(down[v],make_pair(-d, 1));
			F.add(up  [v],make_pair( d,-1));
		}

		for(query a:Q[c]){
			int u=a.u,v=a.v,d=a.d;
			int w=L.lca(u,v);
			auto b=F.sum(down[w]+1,down[u])+F.sum(down[w]+1,down[v]);
			ans[a.id]=b.first+d*b.second;
		}

		for(edge e:E[c]){
			int u=e.u,v=e.v,d=e.d;
			if(L.dep[u]>L.dep[v]) swap(u,v);
			F.add(down[v],make_pair( d,-1));
			F.add(up  [v],make_pair(-d, 1));
		}
	}

	rep(i,q) printf("%d\n",ans[i]);

	return 0;
}
