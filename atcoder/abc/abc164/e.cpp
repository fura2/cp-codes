#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> struct edge{
	int to;
	T wt1,wt2;
	edge(int to,const T& wt1,const T& wt2):to(to),wt1(wt1),wt2(wt2){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

const long long INF=1LL<<61;

int main(){
	int n,m,k0; scanf("%d%d%d",&n,&m,&k0);
	k0=min(k0,2500);
	weighted_graph<lint> G(n);
	rep(i,m){
		int u,v,c1,c2; scanf("%d%d%d%d",&u,&v,&c1,&c2); u--; v--;
		G[u].emplace_back(v,c1,c2);
		G[v].emplace_back(u,c1,c2);
	}
	vector<int> c1(n),c2(n);
	rep(u,n) scanf("%d%d",&c1[u],&c2[u]);

	lint d[50][2501];
	rep(u,n) rep(k,2501) d[u][k]=INF;
	d[0][k0]=0;

	priority_queue<pair<lint,pair<int,int>>> Q;
	Q.emplace(0,make_pair(0,k0));
	while(!Q.empty()){
		lint d0=-Q.top().first;
		int u,k; tie(u,k)=Q.top().second; Q.pop();

		if(d0>d[u][k]) continue;

		// 換金
		int k2=min(k+c1[u],2500);
		lint d2=d0+c2[u];
		if(d2<d[u][k2]){
			d[u][k2]=d2;
			Q.emplace(-d2,make_pair(u,k2));
		}

		// 移動
		for(auto e:G[u]) if(e.wt1<=k) {
			int v=e.to;
			k2=k-e.wt1;
			d2=d0+e.wt2;
			if(d2<d[v][k2]){
				d[v][k2]=d2;
				Q.emplace(-d2,make_pair(v,k2));
			}
		}
	}

	for(int u=1;u<n;u++) printf("%lld\n",*min_element(d[u],d[u]+2501));

	return 0;
}
