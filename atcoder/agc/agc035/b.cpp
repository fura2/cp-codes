#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

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

weighted_graph<int> T;
int dir[100000],deg[100000];

void dfs(int u,int p){
	for(auto e:T[u]){
		int v=e.to,i=e.wt;
		if(v==p) continue;

		dfs(v,u);
		if(i>0){
			i--;
			if(deg[v]%2==0) dir[i]= 1, deg[u]++;
			else            dir[i]=-1, deg[v]++;
		}
		else{
			i=-i-1;
			if(deg[v]%2==0) dir[i]=-1, deg[u]++;
			else            dir[i]= 1, deg[v]++;
		}
	}
}

int main(){
	int n,m; scanf("%d%d",&n,&m);

	if(m%2==1) return puts("-1"),0;

	pair<int,int> E[100000];
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		E[i]={u,v};
	}

	T.resize(n);
	union_find U(n);
	rep(i,m){
		int u,v; tie(u,v)=E[i];
		if(!U.is_same(u,v)){
			U.unite(u,v);
			T[u].emplace_back(v, i+1);
			T[v].emplace_back(u,-i-1);
		}
		else{
			dir[i]=1;
			deg[u]++;
		}
	}

	dfs(0,-1);

	rep(i,m){
		int u,v; tie(u,v)=E[i];
		if(dir[i]==1) printf("%d %d\n",u+1,v+1);
		else          printf("%d %d\n",v+1,u+1);
	}

	return 0;
}
