#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

int dep[200000];
vector<int> D[200000];

void dfs(int u,int p,const graph& T){
	D[dep[u]].emplace_back(u);
	for(int v:T[u]) if(v!=p) {
		dep[v]=dep[u]+1;
		dfs(v,u,T);
	}
}

class Euler_tour_for_subtrees{
	vector<int> L,R;
	const graph& Tr;
	int idx;
	void dfs(int u,int p){
		L[u]=idx++;
		for(int v:Tr[u]) if(v!=p) dfs(v,u);
		R[u]=idx;
	}
public:
	Euler_tour_for_subtrees(const graph& Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){
		dfs(root,-1);
	}
	int get_index(int u)const{ return L[u]; }
	pair<int,int> get_subtree(int u)const{ return {L[u],R[u]}; }
};

int main(){
	int n; scanf("%d",&n);
	graph T(n);
	for(int v=1;v<n;v++){
		int u; scanf("%d",&u); u--;
		add_undirected_edge(T,u,v);
	}

	dfs(0,-1,T);

	Euler_tour_for_subtrees ET(T,0);

	int q; scanf("%d",&q);
	rep(_,q){
		int u,d; scanf("%d%d",&u,&d); u--;
		if(dep[u]>d){
			puts("0");
			continue;
		}

		auto [L,R]=ET.get_subtree(u);
		if(D[d].empty() || R<=ET.get_index(D[d][0]) || ET.get_index(D[d].back())<L){
			puts("0");
			continue;
		}

		int lo=-1,hi=int(D[d].size())-1;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			int idx=ET.get_index(D[d][mi]);
			if(L<=idx){
				hi=mi;
			}
			else lo=mi;
		}
		int l=hi;

		lo=0; hi=D[d].size();
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			int idx=ET.get_index(D[d][mi]);
			if(idx<R){
				lo=mi;
			}
			else hi=mi;
		}
		int r=hi;

		printf("%d\n",r-l);
	}

	return 0;
}
