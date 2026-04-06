#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	static char B[2000][2001];
	rep(i,h) scanf("%s",B[i]);

	static int hor[2000][2000],ver[2000][2000];
	rep(i,h) rep(j,w) if(B[i][j]=='.') hor[i][j]=ver[i][j]=1;
	rep(i,h) rep(j,w-1) if(B[i][j+1]=='.') hor[i][j+1]=hor[i][j]+1;
	rep(i,h) for(int j=w-1;j>0;j--) if(B[i][j]=='.' && B[i][j-1]=='.') hor[i][j-1]=hor[i][j];
	rep(j,w) rep(i,h-1) if(B[i+1][j]=='.') ver[i+1][j]=ver[i][j]+1;
	rep(j,w) for(int i=h-1;i>0;i--) if(B[i][j]=='.' && B[i-1][j]=='.') ver[i-1][j]=ver[i][j];

	int ans=0;
	rep(i,h) rep(j,w) ans=max(ans,hor[i][j]+ver[i][j]-1);
	printf("%d\n",ans);

	return 0;
}
