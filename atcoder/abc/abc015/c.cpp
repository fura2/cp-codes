#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,k,a[5][5];

bool dfs(int i,int x){
	if(i==n) return x==0;
	rep(j,k) if(dfs(i+1,x^a[i][j])) return true;
	return false;
}

int main(){
	scanf("%d%d",&n,&k);
	rep(i,n) rep(j,k) scanf("%d",&a[i][j]);
	puts(dfs(0,0)?"Found":"Nothing");
	return 0;
}
