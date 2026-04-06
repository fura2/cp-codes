#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
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

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> x(m),y(m);
	rep(i,m) scanf("%d%d",&y[i],&x[i]);

	vector<vector<pair<int,int>>> X(2*m+1);
	rep(i,m) if(n-m<=x[i] && x[i]<=n+m) {
		int x2=x[i]-(n-m);
		X[x2].emplace_back(y[i],1);
		if(x2> 0 ) X[x2-1].emplace_back(y[i]-1,0);
		if(x2<2*m) X[x2+1].emplace_back(y[i]-1,0);
	}
	X[m].emplace_back(0,0); // start
	rep(c,2*m+1){
		X[c].emplace_back(2e9,0); // goal
	}
	rep(c,2*m+1){
		sort(X[c].begin(),X[c].end());
		X[c].erase(unique(X[c].begin(),X[c].end()),X[c].end());
		vector<pair<int,int>> tmp;
		for(auto [y,t]:X[c]){
			if(!tmp.empty() && tmp.back()==make_pair(y,0)) tmp.pop_back();
			tmp.emplace_back(y,t);
		}
		X[c]=tmp;
	}

	int N=0;
	vector<vector<int>> idx(2*m+1);
	rep(c,2*m+1){
		idx[c].resize(X[c].size());
		rep(i,X[c].size()){
			idx[c][i]=N++;
		}
	}

	graph G(N);
	rep(c,2*m+1){
		rep(i,X[c].size()){
			auto [y,t]=X[c][i];
			int u=idx[c][i];
			for(int dx:{-1,1}){
				int c2=c+dx;
				if(0<=c2 && c2<=2*m){
					int j=lower_bound(X[c2].begin(),X[c2].end(),make_pair(y+1,1))-X[c2].begin();
					if(j<X[c2].size() && X[c2][j]==make_pair(y+1,1)){
						int v=idx[c2][j];
						add_directed_edge(G,u,v);
					}
				}
			}
			if(i+1<X[c].size() && X[c][i+1].second==0){
				int v=idx[c][i+1];
				add_directed_edge(G,u,v);
			}
		}
	}

	auto d=distance(G,idx[m][0]);

	int ans=0;
	rep(c,2*m+1) if(d[idx[c].back()]<INT_MAX) ans++;
	printf("%d\n",ans);

	return 0;
}
