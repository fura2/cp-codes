#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,q; scanf("%d%d%d",&h,&w,&q);
	static char B[2000][2001];
	rep(i,h) scanf("%s",B[i]);

	static int sum1[2001][2001],sum2[2000][2001],sum3[2001][2000];
	rep(i,h) rep(j,w) sum1[i+1][j+1]=sum1[i+1][j]+sum1[i][j+1]-sum1[i][j]+(B[i][j]-'0');
	rep(i,h-1) rep(j,w) sum2[i+1][j+1]=sum2[i+1][j]+sum2[i][j+1]-sum2[i][j]+(B[i][j]=='1'&&B[i+1][j]=='1'?1:0);
	rep(i,h) rep(j,w-1) sum3[i+1][j+1]=sum3[i+1][j]+sum3[i][j+1]-sum3[i][j]+(B[i][j]=='1'&&B[i][j+1]=='1'?1:0);

	rep(_,q){
		int y1,x1,y2,x2; scanf("%d%d%d%d",&y1,&x1,&y2,&x2); y1--; x1--;
		int ans=0;
		ans+=sum1[y2][x2]-sum1[y1][x2]-sum1[y2][x1]+sum1[y1][x1];
		ans-=sum2[y2-1][x2]-sum2[y1][x2]-sum2[y2-1][x1]+sum2[y1][x1];
		ans-=sum3[y2][x2-1]-sum3[y1][x2-1]-sum3[y2][x1]+sum3[y1][x1];
		printf("%d\n",ans);
	}

	return 0;
}
