#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

template<class T>
class network{
	struct edge{
		int to,rev;
		T capa,flow;
		edge(int to,int rev,const T& capa,const T& flow):to(to),rev(rev),capa(capa),flow(flow){}
	};

	int s,t;
	vector<vector<edge>> G;

	vector<int> layer,now;

	bool make_layer(){
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

	T augment(int u,const T& water){
		if(u==t) return water;

		for(int& i=now[u];i<G[u].size();i++){
			edge& e=G[u][i];
			if(layer[e.to]>layer[u] && e.capa-e.flow>0){
				T w=augment(e.to,min(water,e.capa-e.flow));
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
	network(int n,int s,int t):s(s),t(t){
		G.resize(n);
	}

	void add_directed_edge(int u,int v,const T& capa){
		G[u].emplace_back(v,G[v].size()  ,capa,0);
		G[v].emplace_back(u,G[u].size()-1,   0,0);
	}

	T maximum_flow(){
		int n=G.size();
		layer.resize(n);

		T res=0;
		while(make_layer()){
			now.assign(n,0);
			for(T water=1;water>0;res+=water) water=augment(s,numeric_limits<T>::max());
		}
		return res;
	}
};

int main(){
	int h,w; scanf("%d%d",&h,&w);
	char B[100][101];
	rep(i,h) scanf("%s",B[i]);

	int sx,sy,tx,ty;
	rep(i,h) rep(j,w) {
		if(B[i][j]=='S') tie(sy,sx)=tie(i,j);
		if(B[i][j]=='T') tie(ty,tx)=tie(i,j);
	}

	network<int> G(2*h*w,sy*w+sx+h*w,ty*w+tx);
	rep(i,h) rep(j,w) if(B[i][j]!='.') {
		G.add_directed_edge(i*w+j,i*w+j+h*w,1);
		rep(k,h) if(k!=i && B[k][j]!='.') G.add_directed_edge(i*w+j+h*w,k*w+j,INF);
		rep(k,w) if(k!=j && B[i][k]!='.') G.add_directed_edge(i*w+j+h*w,i*w+k,INF);
	}

	int ans=G.maximum_flow();
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
