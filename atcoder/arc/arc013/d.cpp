#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class bipartite_graph{
	int L,R;
	vector<vector<int>> G,match;
	vector<bool> vis;

	bool augment(int u){
		if(u==-1) return true;
		for(int v:G[u]) if(!vis[v]) {
			vis[v]=true;
			if(augment(match[1][v])){
				match[0][u]=v;
				match[1][v]=u;
				return true;
			}
		}
		return false;
	}

public:
	bipartite_graph(int L,int R):L(L),R(R),G(L){}

	void add_edge(int u,int v){ G[u].emplace_back(v); }

	const vector<int>& operator[](int u)const{ return G[u]; }

	pair<int,vector<vector<int>>> bipartite_matching(){
		match.resize(2);
		match[0].assign(L,-1);
		match[1].assign(R,-1);

		int res=0;
		vis.resize(R);
		rep(u,L){
			fill(vis.begin(),vis.end(),false);
			if(augment(u)) res++;
		}

		return {res,match};
	}
};

int main(){
	int n; scanf("%d",&n);

	vector<int> x(n),y(n),z(n),S;
	rep(i,n){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		for(int d=1;d<x[i];d++){
			S.emplace_back(d*y[i]*z[i]);
			S.emplace_back((x[i]-d)*y[i]*z[i]);
		}
		for(int d=1;d<y[i];d++){
			S.emplace_back(x[i]*d*z[i]);
			S.emplace_back(x[i]*(y[i]-d)*z[i]);
		}
		for(int d=1;d<z[i];d++){
			S.emplace_back(x[i]*y[i]*d);
			S.emplace_back(x[i]*y[i]*(z[i]-d));
		}
	}
	sort(S.begin(),S.end());
	S.erase(unique(S.begin(),S.end()),S.end());

	bipartite_graph G(S.size(),S.size());
	rep(i,n){
		for(int d=1;d<x[i];d++){
			int u=lower_bound(S.begin(),S.end(),d*y[i]*z[i])-S.begin();
			int v=lower_bound(S.begin(),S.end(),(x[i]-d)*y[i]*z[i])-S.begin();
			G.add_edge(u,v);
			G.add_edge(v,u);
		}
		for(int d=1;d<y[i];d++){
			int u=lower_bound(S.begin(),S.end(),x[i]*d*z[i])-S.begin();
			int v=lower_bound(S.begin(),S.end(),x[i]*(y[i]-d)*z[i])-S.begin();
			G.add_edge(u,v);
			G.add_edge(v,u);
		}
		for(int d=1;d<z[i];d++){
			int u=lower_bound(S.begin(),S.end(),x[i]*y[i]*d)-S.begin();
			int v=lower_bound(S.begin(),S.end(),x[i]*y[i]*(z[i]-d))-S.begin();
			G.add_edge(u,v);
			G.add_edge(v,u);
		}
	}
	printf("%lu\n",2*S.size()-G.bipartite_matching().first);

	return 0;
}
