#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,m,q,a[50],b[50],c[50],d[50];

int v[10];

int dfs(int i,int pre){
	if(i==n){
		int res=0;
		rep(j,q) if(v[b[j]]-v[a[j]]==c[j]) res+=d[j];
		return res;
	}

	int res=0;
	for(int x=pre;x<=m;x++){
		v[i]=x;
		res=max(res,dfs(i+1,x));
	}
	return res;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,q) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]), a[i]--, b[i]--;

	printf("%d\n",dfs(0,1));

	return 0;
}
