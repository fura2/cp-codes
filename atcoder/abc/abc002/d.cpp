#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; cin>>n>>m;
	int to[12]={};
	rep(i,m){
		int u,v; cin>>u>>v; u--; v--;
		to[u]|=1<<v;
		to[v]|=1<<u;
	}

	int ans=0;
	rep(S,1<<n){
		bool ok=true;
		int cnt=0;
		rep(u,n) if(S&(1<<u)) {
			if((S&to[u])!=S-(1<<u)) ok=false;
			cnt++;
		}
		if(ok) ans=max(ans,cnt);
	}
	printf("%d\n",ans);

	return 0;
}
