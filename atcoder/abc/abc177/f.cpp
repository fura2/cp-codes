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
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				Q.emplace(-d[v],v);
			}
		}
	}
	return d;
}

const int INF=1<<29;

class segment_tree_dual{
	int n;
	vector<int> seg;

	void update(int l,int r,int a,int b,int u,int x){
		if(l<=a && b<=r){ seg[u]=min(seg[u],x); return; }
		int c=(a+b+1)/2;
		if(l<c && a<r) update(l,r,a,c,2*u  ,x);
		if(l<b && c<r) update(l,r,c,b,2*u+1,x);
	}

public:
	segment_tree_dual(int N){
		for(n=1;n<N;n*=2);
		seg.assign(2*n,INF);
	}

	void update(int l,int r,int x){ update(l,r,0,n,1,x); }

	int get(int u){
		u+=n;
		int res=seg[u];
		for(u/=2;u>=1;u/=2) res=min(res,seg[u]);
		return res;
	}
};

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector<int> l(h),r(h);
	rep(i,h) scanf("%d%d",&l[i],&r[i]), l[i]--;

	vector pos(h+1,vector<int>());
	{
		segment_tree_dual S(w);
		S.update(0,w,h);
		for(int i=h-1;i>0;i--){
			if(r[i]<w){
				pos[i].emplace_back(r[i]);
				pos[S.get(r[i])].emplace_back(r[i]);
			}
			S.update(l[i],r[i],i);
		}
		rep(x,w) if(!(l[0]<=x && x<r[0])) {
			pos[0].emplace_back(x);
			pos[S.get(x)].emplace_back(x);
		}
	}
	rep(i,h+1){
		sort(pos[i].begin(),pos[i].end());
		pos[i].erase(unique(pos[i].begin(),pos[i].end()),pos[i].end());
	}

	int N=0;
	vector f(h+1,vector<int>()); // vertex id
	rep(i,h+1){
		f[i].resize(pos[i].size());
		rep(j,pos[i].size()) f[i][j]=N++;
	}

	int src=N;
	N++;
	weighted_graph<int> G(N);
	vector<int> nxt(w,-1);
	for(int i=h;i>=0;i--) rep(j,pos[i].size()) {
		int x=pos[i][j],u=f[i][j];
		if(j+1<pos[i].size()){
			add_directed_edge(G,u,u+1,pos[i][j+1]-x);
		}
		if(!(l[i]<=x && x<r[i]) && nxt[x]!=-1){
			add_directed_edge(G,u,nxt[x],0);
		}
		nxt[x]=u;
	}
	for(int u:f[0]){
		add_directed_edge(G,src,u,0);
	}

	auto d=Dijkstra(G,src);

	vector<int> ans(h+1,INF);
	rep(i,h+1) for(int u:f[i]) {
		ans[i]=min(ans[i],d[u]);
	}
	for(int i=h;i>0;i--){
		ans[i-1]=min(ans[i-1],ans[i]);
	}
	for(int i=1;i<=h;i++){
		printf("%d\n",ans[i]<INF?ans[i]+i:-1);
	}

	return 0;
}
