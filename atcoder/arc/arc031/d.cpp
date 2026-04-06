#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class capa_t>
class mf_graph{
	struct edge{
		int to,rev;
		capa_t capa,flow;
		edge(int to,int rev,const capa_t& capa,const capa_t& flow):to(to),rev(rev),capa(capa),flow(flow){}
	};

	vector<vector<edge>> G;
	vector<int> layer,cur;

	bool make_layer(int s,int t){
		int n=G.size();
		rep(u,n) layer[u]=(u==s?0:-1);

		queue<int> Q; Q.emplace(s);
		while(!Q.empty()){
			int u=Q.front(); Q.pop();
			for(const edge& e:G[u]) if(layer[e.to]==-1 && e.capa-e.flow>0) {
				layer[e.to]=layer[u]+1;
				if(e.to==t) return true;
				Q.emplace(e.to);
			}
		}
		return false;
	}

	capa_t augment(int u,int t,const capa_t& water){
		if(u==t) return water;

		for(int& i=cur[u];i<G[u].size();i++){
			edge& e=G[u][i];
			if(layer[e.to]>layer[u] && e.capa-e.flow>0){
				capa_t w=augment(e.to,t,min(water,e.capa-e.flow));
				if(w>0){
					e.flow+=w;
					G[e.to][e.rev].flow-=w;
					return w;
				}
			}
		}
		return 0;
	}

public:
	mf_graph(){}
	mf_graph(int n):G(n){}

	void add_directed_edge(int u,int v,const capa_t& capa){
		G[u].emplace_back(v,G[v].size()  ,capa,0);
		G[v].emplace_back(u,G[u].size()-1,   0,0);
	}

	void add_undirected_edge(int u,int v,const capa_t& capa){
		G[u].emplace_back(v,G[v].size()  ,capa,0);
		G[v].emplace_back(u,G[u].size()-1,capa,0);
	}

	capa_t maximum_flow(int s,int t){
		int n=G.size();
		layer.resize(n);

		capa_t res=0;
		while(make_layer(s,t)){
			cur.assign(n,0);
			for(capa_t water=1;water>0;res+=water){
				water=augment(s,t,numeric_limits<capa_t>::max());
			}
		}
		return res;
	}

	vector<int> minimum_cut(int s){
		int n=G.size();
		vector<int> res;
		vector<bool> vis(n);
		vis[s]=true;
		queue<int> Q;
		Q.emplace(s);
		while(!Q.empty()){
			int u=Q.front(); Q.pop();
			res.emplace_back(u);
			// for(const edge& e:G[u]) if(!vis[e.to] && e.capa-e.flow>0) {
			for(const edge& e:G[u]) if(!vis[e.to] && e.capa-e.flow>1e-8) {
				vis[e.to]=true;
				Q.emplace(e.to);
			}
		}
		return res;
	}
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> val(n),cost(m);
	rep(i,n) scanf("%d",&val[i]);
	rep(i,m) scanf("%d",&cost[i]);
	vector a(n,vector<int>());
	rep(i,n){
		int k; scanf("%d",&k);
		a[i].resize(k);
		rep(j,k) scanf("%d",&a[i][j]), a[i][j]--;
	}

	int vsum=accumulate(val.begin(),val.end(),0);

	double lo=0,hi=1e4;
	rep(_,50){
		double mi=(lo+hi)/2;

		int N=m+n+2;
		int s=N-2,t=N-1;
		mf_graph<double> G(N);
		rep(i,m){
			G.add_directed_edge(i,t,cost[i]*mi);
		}
		rep(i,n){
			G.add_directed_edge(s,m+i,val[i]);
			rep(j,a[i].size()){
				G.add_directed_edge(m+i,a[i][j],1e8);
			}
		}

		if(G.maximum_flow(s,t)<vsum) lo=mi;
		else                         hi=mi;
	}
	printf("%.9f\n",lo);

	return 0;
}
