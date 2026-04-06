#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

const int INF=1<<29;

int n;
graph T;

int r,cnt,d_max[200000],d_min[200000];

void dfs(int u,int p){
	d_min[u]=INF;
	for(int v:T[u]) if(v!=p) {
		dfs(v,u);
		d_min[u]=min(d_min[u],d_min[v]+1);
	}

	d_max[u]=0;
	for(int v:T[u]) if(v!=p) {
		if(d_max[v]>0 || (d_max[v]==0 && d_min[v]>r)){
			d_max[u]=max(d_max[u],d_max[v]+1);
		}
	}
	if(d_min[u]<=r && r-d_min[u]>=d_max[u]){
		d_max[u]=0;
	}

	assert(d_max[u]<=r);
	if(d_max[u]==r){
		d_max[u]=d_min[u]=0;
		cnt++;
	}
}

int main(){
	int k; scanf("%d%d",&n,&k);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	int lo=-1,hi=n-1;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		r=mi;
		cnt=0;
		dfs(0,-1);
		if(d_max[0]>0 || (d_max[0]==0 && d_min[0]>r)) cnt++;

		if(cnt<=k) hi=mi;
		else       lo=mi;
	}
	printf("%d\n",hi);

	return 0;
}
