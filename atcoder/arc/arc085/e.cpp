#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class capa_t>
class mf_graph{
	struct edge{
		int to,rev;
		capa_t capa,flow;
		edge(int to,int rev,const capa_t& capa,const capa_t& flow):to(to),rev(rev),capa(capa),flow(flow){}
	};

	vector<vector<edge>> G;

public:
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
		vector<int> pre(n);
		vector<bool> vis(n);

		auto augment=[&](){
			rep(u,n) vis[u]=(u==s);

			queue<pair<int,capa_t>> Q; Q.emplace(s,0);
			for(const edge& e:G[s]){
				Q.front().second=max(Q.front().second,e.capa-e.flow);
			}

			capa_t res=0;
			while(!Q.empty()){
				int u;
				capa_t water; tie(u,water)=Q.front(); Q.pop();

				if(u==t){ res=water; break; }

				for(const edge& e:G[u]) if(!vis[e.to] && e.capa-e.flow>0) {
					vis[e.to]=true;
					pre[e.to]=e.rev;
					Q.emplace(e.to,min(water,e.capa-e.flow));
				}
			}

			if(res>0){
				for(int u=t;u!=s;){
					edge& e1=G[u][pre[u]];
					edge& e2=G[e1.to][e1.rev];
					e1.flow-=res;
					e2.flow+=res;
					u=e1.to;
				}
			}

			return res;
		};

		capa_t res=0;
		for(capa_t water=1;water>0;res+=water) water=augment();
		return res;
	}
};

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	lint res=0;
	int s=0,t=n+1; // s 側 : 壊す, t 側 : 残す
	mf_graph<lint> G(n+2);
	rep(i,n){
		int x=i+1;
		if(a[i]>=0){
			res+=a[i];
			G.add_directed_edge(x,t,a[i]);
		}
		else{
			G.add_directed_edge(s,x,-a[i]);
		}
		for(int y=2*x;y<=n;y+=x){
			G.add_directed_edge(x,y,INF);
		}
	}

	printf("%lld\n",res-G.maximum_flow(s,t));

	return 0;
}
