#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,k;

double memo[1001][1001][2];

// i 枚見終わって, そのうち j 枚食べて,  b: ここまでの最大を食べたかどうか
double dfs(int i,int j,bool b){
	if(j>k) return 0;

	double& res=memo[i][j][b];
	if(res!=-1) return res;

	if(i==n) return res=(b?1:0);

	res=0;
	// 次がここまでの最大のとき
	res+=max(dfs(i+1,j+1,1),dfs(i+1,j,0))/(i+1);
	// 次がここまでの最大ではないとき
	res+=dfs(i+1,j,b)*i/(i+1);
	return res;
}

int main(){
	scanf("%d%d",&n,&k);

	rep(i,n+1) rep(j,k+1) rep(b,2) memo[i][j][b]=-1;

	printf("%.9f\n",dfs(0,0,false));

	return 0;
}
