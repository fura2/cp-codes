#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int h,w; cin>>h>>w;
	string B[50];
	rep(i,h) cin>>B[i];

	int d[50][50];
	rep(i,h) rep(j,w) d[i][j]=(i==0&&j==0?0:-1);

	int Q[50*50],l=0,r=0;
	Q[r++]=0;
	while(l<r){
		int p=Q[l++];
		int y=p/w,x=p%w;
		rep(k,4){
			int yy=y+dy[k],xx=x+dx[k];
			if(0<=yy && yy<h && 0<=xx && xx<w && !~d[yy][xx] && B[yy][xx]=='.'){
				d[yy][xx]=d[y][x]+1;
				Q[r++]=yy*w+xx;
			}
		}
	}

	if(!~d[h-1][w-1]){ cout<<-1<<endl; return 0; }

	int ans=h*w-d[h-1][w-1]-1;
	rep(i,h) rep(j,w) if(B[i][j]=='#') ans--;
	cout<<ans<<endl;

	return 0;
}
