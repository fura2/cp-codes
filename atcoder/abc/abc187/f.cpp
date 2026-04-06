#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int A[18]={};
	rep(u,n) A[u]|=1<<u;
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		A[u]|=1<<v;
		A[v]|=1<<u;
	}

	vector clique(1<<n,0);
	rep(S,1<<n){
		bool ok=true;
		rep(u,n) if(S>>u&1 && !((S&A[u])==S)) ok=false;
		clique[S]=ok;
	}

	vector dp(1<<n,INF);
	dp[0]=0;
	rep(S,1<<n){
		for(int T=S;T>=0;T--){
			T&=S;
			if(clique[S&~T]){
				dp[S]=min(dp[S],dp[T]+clique[S&~T]);
			}
		}
	}
	printf("%d\n",dp[(1<<n)-1]);

	return 0;
}
