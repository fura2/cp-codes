#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	int sum[101][101]={};
	rep(i,h) rep(j,w) {
		int x; scanf("%d",&x);
		if((i+j)%2==0) sum[i+1][j+1]+=x;
		else           sum[i+1][j+1]-=x;
	}

	rep(i,h) rep(j,w) sum[i+1][j+1]+=sum[i+1][j]+sum[i][j+1]-sum[i][j];

	int ans=0;
	rep(i,h) for(int y=i+1;y<=h;y++) rep(j,w) for(int x=j+1;x<=w;x++) {
		if(sum[y][x]-sum[y][j]-sum[i][x]+sum[i][j]==0) ans=max(ans,(y-i)*(x-j));
	}
	printf("%d\n",ans);

	return 0;
}
