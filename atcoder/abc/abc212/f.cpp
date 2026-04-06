#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n=0){ build(n); }
	void build(int n){
		this->n=n;
		p.assign(n,-1);
	}
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
	int n,m,q; scanf("%d%d%d",&n,&m,&q);

	vector<tuple<int,int,int,int>> E(m);
	rep(i,m){
		int u,v,s,t; scanf("%d%d%d%d",&u,&v,&s,&t); u--; v--;
		E[i]={u,v,s,t};
	}
	vector<tuple<int,int,int>> Q(q);
	rep(i,q){
		int x,y,z; scanf("%d%d%d",&x,&y,&z); y--;
		Q[i]={x,y,z};
	}

	enum{EDGE_TO,EDGE_FROM,QUERY_TO,QUERY_FROM};
	vector<tuple<double,int,int>> Ev;
	rep(i,m){
		auto [u,v,s,t]=E[i];
		Ev.emplace_back(s+0.5,EDGE_FROM,i);
		Ev.emplace_back(t+0.5,EDGE_TO,i);
	}
	rep(i,q){
		auto [x,y,z]=Q[i];
		Ev.emplace_back(x,QUERY_FROM,i);
		Ev.emplace_back(z,QUERY_TO,i);
	}

	sort(Ev.begin(),Ev.end());

	union_find U(q);
	vector<int> V(n,-1); // V[u] = (頂点 u にいる人の集合 (代表元))
	vector<int> F(m,-1); // f[e] = (辺 e を移動中の人の集合 (代表元))
	enum{VERTEX,EDGE};
	vector<pair<int,int>> inv(q); // inverse of V, F

	vector<pair<int,int>> ans(q);
	for(auto [t,type,id]:Ev){
		if(type==EDGE_FROM){
			int e=id;
			int u=get<0>(E[e]);
			if(V[u]!=-1){
				int i=U.find(V[u]);
				F[e]=i;
				inv[F[e]]={EDGE,e};
				V[u]=-1;
			}
		}
		else if(type==EDGE_TO){
			int e=id;
			int v=get<1>(E[e]);
			if(F[e]!=-1){
				if(V[v]!=-1) U.unite(V[v],F[e]);
				else         V[v]=F[e];
				V[v]=U.find(V[v]);
				inv[V[v]]={VERTEX,v};
				F[e]=-1;
			}
		}
		else if(type==QUERY_FROM){
			int i=id;
			int u=get<1>(Q[i]);
			if(V[u]!=-1) U.unite(V[u],i);
			else         V[u]=i;
			V[u]=U.find(V[u]);
			inv[V[u]]={VERTEX,u};
		}
		else{ // type==QUERY_TO
			int i=id;
			ans[i]=inv[U.find(i)];
		}
	}

	rep(i,q){
		if(ans[i].first==VERTEX){
			printf("%d\n",ans[i].second+1);
		}
		else{
			int e=ans[i].second;
			printf("%d %d\n",get<0>(E[e])+1,get<1>(E[e])+1);
		}
	}

	return 0;
}
