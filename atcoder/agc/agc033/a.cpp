#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int h,w; scanf("%d%d",&h,&w);
	static char B[1000][1001];
	rep(i,h) scanf("%s",B[i]);

	static int d[1000][1000];
	memset(d,-1,sizeof d);
	queue<pair<int,int>> Q;
	rep(i,h) rep(j,w) if(B[i][j]=='#') {
		d[i][j]=0;
		Q.emplace(i,j);
	}
	while(!Q.empty()){
		int y,x;
		tie(y,x)=Q.front(); Q.pop();

		rep(k,4){
			int yy=y+dy[k],xx=x+dx[k];
			if(0<=yy && yy<h && 0<=xx && xx<w && d[yy][xx]==-1){
				d[yy][xx]=d[y][x]+1;
				Q.emplace(yy,xx);
			}
		}
	}

	int ans=0;
	rep(i,h) rep(j,w) ans=max(ans,d[i][j]);
	printf("%d\n",ans);

	return 0;
}
