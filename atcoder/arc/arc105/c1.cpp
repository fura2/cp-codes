#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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
vector<T> Bellman_Ford(const weighted_graph<T>& G,int s){
	const T INF=numeric_limits<T>::max();
	const T NINF=numeric_limits<T>::min();

	int n=G.size();
	vector<T> d(n,INF);
	d[s]=0;
	rep(_,n){
		bool upd=false;
		rep(u,n) if(d[u]<INF) for(const auto& e:G[u]) {
			int v=e.to;
			if(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt, upd=true;
		}
		if(!upd) return d;
	}

	queue<int> Q;
	rep(u,n) if(d[u]<INF) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>NINF && (d[u]==NINF || d[v]>d[u]+e.wt)) d[v]=NINF, Q.emplace(v);
		}
	}
	return d;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<lint> w(n),l(m),v(m);
	rep(i,n) scanf("%lld",&w[i]);
	rep(j,m) scanf("%lld%lld",&l[j],&v[j]);

	if(*max_element(w.begin(),w.end())>*min_element(v.begin(),v.end())){
		puts("-1");
		return 0;
	}

	{
		vector<int> p(m);
		iota(p.begin(),p.end(),0);
		sort(p.begin(),p.end(),[&](int i,int j){
			return make_pair(v[i],-l[i])<make_pair(v[j],-l[j]);
		});

		vector<lint> v2,l2;
		rep(j,m){
			if(v2.empty() || l2.back()<l[p[j]]){
				v2.emplace_back(v[p[j]]);
				l2.emplace_back(l[p[j]]);
			}
		}
		v=v2;
		l=l2;
		m=v.size();
	}

	lint lo=-1,hi=1e9;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		bool ok=false;
		vector<int> p(n);
		iota(p.begin(),p.end(),0);
		do{
			vector<lint> wsum(n+1);
			rep(i,n) wsum[i+1]=wsum[i]+w[p[i]];

			weighted_graph<lint> G(n);
			add_directed_edge(G,0,n-1,mi);
			rep(i,n-1){
				add_directed_edge(G,i+1,i,0LL);
			}
			rep(i,n) for(int j=i+1;j<n;j++) {
				int idx=lower_bound(v.begin(),v.end(),wsum[j+1]-wsum[i])-v.begin()-1;
				if(idx>=0){
					add_directed_edge(G,j,i,-l[idx]);
				}
			}

			auto d=Bellman_Ford(G,0);
			if(count(d.begin(),d.end(),LLONG_MIN)==0){
				ok=true;
				break;
			}
		}while(next_permutation(p.begin(),p.end()));

		if(ok) hi=mi;
		else   lo=mi;
	}
	printf("%lld\n",hi);

	return 0;
}
