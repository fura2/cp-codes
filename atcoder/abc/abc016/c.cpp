#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	bool A[10][10]={};
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		A[u][v]=A[v][u]=true;
	}

	rep(u,n){
		bool f[10]={};
		rep(v,n) if(A[u][v]) rep(w,n) if(A[v][w] && w!=u) f[w]=true;
		rep(v,n) if(A[u][v]) f[v]=false;
		printf("%ld\n",count(f,f+n,true));
	}

	return 0;
}
