#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

vector<int> distance(const graph& G,int s){
	constexpr int INF=INT_MAX;
	int n=G.size();
	vector<int> d(n,INF);
	d[s]=0;
	queue<int> Q; Q.emplace(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(d[v]==INF) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}
	return d;
}

template<class T>
T Hamiltonian_path(const vector<vector<T>>& A){
	constexpr T INF=numeric_limits<T>::max();
	int n=A.size();
	vector dp(1<<n,vector(n,INF));
	rep(u,n) dp[1<<u][u]=0;
	rep(S,1<<n) rep(u,n) if(S>>u&1 && dp[S][u]<INF) {
		rep(v,n) if(~S>>v&1 && A[u][v]<INF) {
			dp[S|1<<v][v]=min(dp[S|1<<v][v],dp[S][u]+A[u][v]);
		}
	}

	T res=INF;
	rep(u,n) res=min(res,dp[(1<<n)-1][u]);
	return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}
	int k; scanf("%d",&k);
	vector<int> C(k);
	rep(i,k) scanf("%d",&C[i]), C[i]--;

	vector A(k,vector<int>(k));
	rep(i,k){
		auto tmp=distance(G,C[i]);
		rep(j,k) A[i][j]=tmp[C[j]];
	}

	int res=Hamiltonian_path(A);
	printf("%d\n",res<INT_MAX?res+1:-1);

	return 0;
}
