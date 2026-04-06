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

// 01-BFS
vector<int> distance(const weighted_graph<int>& G,int s){
	constexpr int INF=INT_MAX;
	int n=G.size();
	vector<int> d(n,INF); d[s]=0;
	deque<int> Q; Q.emplace_back(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop_front();
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				if(e.wt==0) Q.emplace_front(v);
				else        Q.emplace_back(v);
			}
		}
	}
	return d;
}

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector<pair<int,int>> P[26];
	rep(i,h) rep(j,w) if(islower(B[i][j])) P[B[i][j]-'a'].emplace_back(i,j);

	weighted_graph<int> G(h*w+26);
	rep(i,h) rep(j,w) if(B[i][j]!='#') {
		if(i+1<h && B[i+1][j]!='#') add_undirected_edge(G,i*w+j,(i+1)*w+j,1);
		if(j+1<w && B[i][j+1]!='#') add_undirected_edge(G,i*w+j,i*w+(j+1),1);
		if(islower(B[i][j])){
			add_directed_edge(G,i*w+j,h*w+B[i][j]-'a',0);
			add_directed_edge(G,h*w+B[i][j]-'a',i*w+j,1);
		}
	}

	int sx,sy,gx,gy;
	rep(i,h) rep(j,w) {
		if(B[i][j]=='S') sx=i, sy=j;
		if(B[i][j]=='G') gx=i, gy=j;
	}

	int ans=distance(G,sx*w+sy)[gx*w+gy];
	printf("%d\n",ans<INT_MAX?ans:-1);

	return 0;
}
