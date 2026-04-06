// 最長路問題として解く

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

const long long INF=1LL<<61;

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

	lint ans=INF;
	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	do{
		vector<lint> wsum(n+1);
		rep(i,n) wsum[i+1]=wsum[i]+w[p[i]];

		weighted_graph<lint> G(n);
		rep(i,n-1){
			add_directed_edge(G,i,i+1,0LL);
		}
		rep(i,n) for(int j=i+1;j<n;j++) {
			int idx=lower_bound(v.begin(),v.end(),wsum[j+1]-wsum[i])-v.begin()-1;
			if(idx>=0){
				add_directed_edge(G,i,j,l[idx]);
			}
		}

		vector<lint> dp(n);
		rep(i,n) for(auto e:G[i]) dp[e.to]=max(dp[e.to],dp[i]+e.wt);
		ans=min(ans,dp[n-1]);
	}while(next_permutation(p.begin(),p.end()));

	printf("%lld\n",ans);

	return 0;
}
