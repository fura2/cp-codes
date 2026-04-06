#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

double memo[101][101][101];

double dfs(int a,int b,int c){
	if(memo[a][b][c]!=-1) return memo[a][b][c];
	double& res=memo[a][b][c];
	if(a>=100 || b>=100 || c>=100) return res=0;
	return res=dfs(a+1,b,c)*a/(a+b+c)+dfs(a,b+1,c)*b/(a+b+c)+dfs(a,b,c+1)*c/(a+b+c)+1;
}

int main(){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);
	rep(i,101) rep(j,101) rep(k,101) memo[i][j][k]=-1;
	printf("%.9f\n",dfs(a,b,c));
	return 0;
}
