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
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	constexpr T INF=numeric_limits<T>::max();
	int n=G.size();
	vector<T> d(n,INF); d[s]=0;
	priority_queue<pair<T,int>> Q; Q.emplace(0,s);
	while(!Q.empty()){
		T d0=-Q.top().first;
		int u=Q.top().second; Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt, Q.emplace(-d[v],v);
		}
	}
	return d;
}

int main(){
	int h,w; cin>>h>>w;
	int sx,sy,gx,gy; cin>>sx>>sy>>gx>>gy; sx--; sy--; gx--; gy--;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	weighted_graph<int> G(h*w);
	rep(i,h) rep(j,w) if(B[i][j]=='.') {
		for(int dx=-2;dx<=2;dx++) for(int dy=-2;dy<=2;dy++) if(dx!=0 || dy!=0) {
			int x=i+dx,y=j+dy;
			if(0<=x && x<h && 0<=y && y<w && B[x][y]=='.'){
				add_directed_edge(G,i*w+j,x*w+y,abs(i-x)+abs(j-y)==1?0:1);
			}
		}
	}

	int ans=Dijkstra(G,sx*w+sy)[gx*w+gy];
	cout<<(ans<INT_MAX?ans:-1)<<'\n';

	return 0;
}
