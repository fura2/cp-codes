#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

template<class T>
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<pair<int,int>> E(m);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		E[i]={u,v};
	}
	vector<int> c(n);
	rep(u,n) scanf("%d",&c[u]);

	vector<int> ans(m,-1);
	vector<bool> used(n,false);
	while(count(used.begin(),used.end(),true)<n){
		int mx=0;
		rep(u,n) if(!used[u]) mx=max(mx,c[u]);
		rep(u,n) if(c[u]==mx) used[u]=true;
		assert(mx>0);

		weighted_graph<int> G(n);
		rep(i,m){
			int u,v; tie(u,v)=E[i];
			if(c[u]==mx && c[u]==c[v]){
				add_directed_edge(G,u,v,i+1);
				add_directed_edge(G,v,u,-(i+1));
			}
			else if(c[u]==mx && c[u]>c[v]){
				ans[i]=0;
			}
			else if(c[v]==mx && c[v]>c[u]){
				ans[i]=1;
			}
		}

		vector<bool> vis(n);
		auto dfs=[&](auto&& dfs,int u,int p)->void{
			for(auto e:G[u]) if(e.to!=p) {
				int id=abs(e.wt)-1;
				if(ans[id]==-1){
					ans[id]=(e.wt>0?0:1);
				}
				if(!vis[e.to]){
					vis[e.to]=true;
					dfs(dfs,e.to,u);
				}
			}
		};

		rep(u,n) if(c[u]==mx && !vis[u]) {
			vis[u]=true;
			dfs(dfs,u,-1);
		}
	}

	rep(i,m) puts(ans[i]==0?"->":"<-");

	return 0;
}
