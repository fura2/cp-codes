#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

inline int popcount(long long x){
	x-=(x>>1)&0x5555555555555555LL;
	x=(x&0x3333333333333333LL)+((x>>2)&0x3333333333333333LL);
	x=(x+(x>>4))&0x0f0f0f0f0f0f0f0fLL;
	x=(x*0x0101010101010101LL)>>56;
	return x;
}

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

weighted_graph<int> T;

pair<bool,lint> dfs(int u,int p,int g){
	if(u==g) return {true,0};

	for(auto e:T[u]) if(e.to!=p) {
		auto tmp=dfs(e.to,u,g);
		if(tmp.first){
			return {true,(1LL<<e.wt)|tmp.second};
		}
	}
	return {false,0};
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v,i);
		T[v].emplace_back(u,i);
	}

	int m; scanf("%d",&m);
	lint E[20];
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b); a--; b--;
		E[i]=dfs(a,-1,b).second;
	}

	lint ans=0;
	rep(S,1<<m){
		lint white=0;
		rep(i,m) if(S>>i&1) white|=E[i];
		ans+=(popcount(S)%2==0?1:-1)*(1LL<<(n-1-popcount(white)));
	}
	printf("%lld\n",ans);

	return 0;
}
