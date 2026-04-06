#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

class strongly_connected_components{
	int idx;
	vector<int> top,id;
	const graph& G;
	graph G_rev;

	vector<vector<int>>Comp;
	graph D;

	void dfs1(int u){
		id[u]=0;
		for(int v:G[u]) if(id[v]==-1) dfs1(v);
		top[idx++]=u;
	}

	void dfs2(int u){
		id[u]=idx;
		for(int v:G_rev[u]) if(id[v]==-1) dfs2(v);
	}

public:
	strongly_connected_components(const graph& G):G(G){
		int n=G.size();
		G_rev.resize(n);
		rep(u,n) for(int v:G[u]) G_rev[v].emplace_back(u);

		idx=0;
		id.assign(n,-1);
		top.resize(n);
		rep(u,n) if(id[u]==-1) dfs1(u);

		reverse(top.begin(),top.end());

		idx=0;
		id.assign(n,-1);
		for(int u:top) if(id[u]==-1) dfs2(u), idx++;

		Comp.resize(idx);
		D.resize(idx);
		rep(u,n){
			Comp[id[u]].emplace_back(u);
			for(int v:G[u]) if(id[u]!=id[v]) D[id[u]].emplace_back(id[v]);
		}
	}

	int operator[](int i)const{ return id[i]; }

	const vector<int>& component(int i)const{ return Comp[i]; }
	const graph& DAG()const{ return D; }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G0(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G0[v].emplace_back(u);
	}

	int k,from[10],to[10]; scanf("%d",&k);
	rep(i,k) scanf("%d%d",&from[i],&to[i]), from[i]--, to[i]--;

	int ans=0;
	rep(S,1<<k){
		graph G=G0;

		vector<bool> ban(n);
		rep(i,k){
			if(S>>i&1) G[from[i]].emplace_back(to[i]);
			else       ban[from[i]]=true;
		}

		strongly_connected_components SCC(G);
		graph D=SCC.DAG();

		vector<bool> ok(D.size(),true);
		rep(i,D.size()){
			auto& C=SCC.component(i);
			if(C.size()>=2 || ban[C[0]]){
				ok[i]=false;
			}
			if(!ok[i]){
				for(int j:D[i]) ok[j]=false;
			}
		}

		ans=max(ans,(int)count(ok.begin(),ok.end(),true));
	}
	printf("%d\n",ans);

	return 0;
}
