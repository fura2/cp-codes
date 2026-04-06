#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int deg[50]={};
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		deg[u]++;
		deg[v]++;
	}
	rep(u,n) printf("%d\n",deg[u]);

	return 0;
}
