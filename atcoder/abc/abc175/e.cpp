#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int h,w,k; scanf("%d%d%d",&h,&w,&k);
	vector B(h,vector(w,0));
	rep(i,k){
		int x,y,v; scanf("%d%d%d",&x,&y,&v); x--; y--;
		B[x][y]=v;
	}

	static lint dp[3000][3000][4];
	rep(i,h) rep(j,w) rep(k,4) dp[i][j][k]=-INF;
	dp[0][0][0]=0;
	if(B[0][0]>0) dp[0][0][1]=B[0][0];
	rep(i,h) rep(j,w) rep(k,4) if(dp[i][j][k]!=-INF) {
		if(i<h-1){
			dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][k]);
			if(B[i+1][j]>0){
				dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][k]+B[i+1][j]);
			}
		}
		if(j<w-1){
			dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]);
			if(B[i][j+1]>0 && k<3){
				dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i][j][k]+B[i][j+1]);
			}
		}
	}
	printf("%lld\n",*max_element(dp[h-1][w-1],dp[h-1][w-1]+4));

	return 0;
}
