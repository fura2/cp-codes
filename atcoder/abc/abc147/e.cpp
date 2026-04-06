#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);

	int B[80][80];
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);
	rep(i,h) rep(j,w) {
		int tmp; scanf("%d",&tmp);
		B[i][j]=abs(B[i][j]-tmp);
	}

	const int OFS=80*80;
	static bool dp[80][80][2*80*80+1];
	dp[0][0][ B[0][0]+OFS]=true;
	dp[0][0][-B[0][0]+OFS]=true;
	rep(i,h) rep(j,w) for(int a=-80*80;a<=80*80;a++) if(dp[i][j][a+OFS]) {
		if(i<h-1 && a+B[i+1][j]<= 80*80) dp[i+1][j][a+B[i+1][j]+OFS]=true;
		if(i<h-1 && a-B[i+1][j]>=-80*80) dp[i+1][j][a-B[i+1][j]+OFS]=true;
		if(j<w-1 && a+B[i][j+1]<= 80*80) dp[i][j+1][a+B[i][j+1]+OFS]=true;
		if(j<w-1 && a-B[i][j+1]>=-80*80) dp[i][j+1][a-B[i][j+1]+OFS]=true;
	}

	int ans=80*80;
	for(int a=-80*80;a<=80*80;a++) if(dp[h-1][w-1][a+OFS]) ans=min(ans,abs(a));
	printf("%d\n",ans);

	return 0;
}
