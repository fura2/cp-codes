#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int A[8][8]={};
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		A[u][v]=A[v][u]=1;
	}

	int ans=0,p[8];
	rep(u,n) p[u]=u;
	do{
		bool ok=true;
		rep(i,n-1) if(A[p[i]][p[i+1]]==0) ok=false;
		if(ok) ans++;
	}while(next_permutation(p+1,p+n));
	printf("%d\n",ans);

	return 0;
}
