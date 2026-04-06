#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	bool A[16][16]={};
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		A[u][v]=true;
	}

	lint dp[1<<16]={};
	dp[0]=1;
	rep(S,1<<n){
		bool ok=true;
		rep(u,n) if(!(S>>u&1)) rep(v,n) if(S>>v&1 && A[u][v]) ok=false;
		if(!ok) continue;
		rep(u,n) if(!(S>>u&1)) dp[S|(1<<u)]+=dp[S];
	}
	printf("%lld\n",dp[(1<<n)-1]);

	return 0;
}
