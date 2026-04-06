#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class two_edge_connected_components{
	int idx;
	vector<int> ord,low,id;
	const vector<vector<int>>& G;

	void dfs1(int u,int p){
		ord[u]=low[u]=idx++;
		bool f=true;
		for(int v:G[u]){
			if(v==p && f){ f=false; continue; }
			if(ord[v]==-1){
				dfs1(v,u);
				low[u]=min(low[u],low[v]);
			}
			else{
				low[u]=min(low[u],ord[v]);
			}
		}
	}

	void dfs2(int u,int p){
		if(p==-1 || ord[p]<low[u]){
			id[u]=idx++;
			if(p!=-1) bridge.emplace_back(minmax(p,u));
		}
		else{
			id[u]=id[p];
		}
		for(int v:G[u]) if(id[v]==-1) dfs2(v,u);
	}

public:
	vector<pair<int,int>> bridge;
	vector<vector<int>> tree;

	two_edge_connected_components(const vector<vector<int>>& G):G(G){
		int n=G.size();

		idx=0;
		ord.assign(n,-1);
		low.assign(n,-1);
		rep(u,n) if(ord[u]==-1) dfs1(u,-1);

		idx=0;
		id.assign(n,-1);
		rep(u,n) if(id[u]==-1) dfs2(u,-1);

		tree.resize(idx);
		rep(u,n) for(int v:G[u]) if(id[u]!=id[v]) tree[id[u]].emplace_back(id[v]);
	}

	int operator[](int i)const{ return id[i]; }
};

int main(){
	int n,m; cin>>n>>m;
	vector<vector<int>> G(n);
	rep(i,m){
		int u,v; cin>>u>>v; u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	cout<<two_edge_connected_components(G).bridge.size()<<endl;

/*
	two_edge_connected_components Te(G);

	int ans=0;
	rep(u,n) for(int v:G[u]) if(Te[u]!=Te[v]) ans++;
	cout<<ans/2<<endl;
*/
	return 0;
}
