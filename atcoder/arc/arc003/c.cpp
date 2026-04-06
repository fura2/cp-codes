#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int h,w; cin>>h>>w;
	string B[500];
	rep(i,h) cin>>B[i];

	int sx,sy,gx,gy;
	rep(i,h) rep(j,w) {
		if(B[i][j]=='s') sx=j, sy=i;
		if(B[i][j]=='g') gx=j, gy=i;
	}

	{
		int d[500][500];
		rep(i,h) rep(j,w) d[i][j]=-1;
		d[sy][sx]=0;
		queue<pair<int,int>> Q; Q.emplace(sx,sy);
		while(!Q.empty()){
			int x,y; tie(x,y)=Q.front(); Q.pop();
			rep(k,4){
				int xx=x+dx[k],yy=y+dy[k];
				if(0<=xx && xx<w && 0<=yy && yy<h && B[yy][xx]!='#' && d[yy][xx]==-1){
					d[yy][xx]=d[y][x]+1;
					Q.emplace(xx,yy);
				}
			}
		}
		if(d[gy][gx]==-1) return cout<<"-1\n",0;
	}

	double lo=0,hi=10;
	rep(_,40){
		double mi=(lo+hi)/2;

		int d[500][500];
		rep(i,h) rep(j,w) d[i][j]=-1;
		d[sy][sx]=0;
		queue<pair<int,int>> Q; Q.emplace(sx,sy);
		while(!Q.empty()){
			int x,y; tie(x,y)=Q.front(); Q.pop();
			rep(k,4){
				int xx=x+dx[k],yy=y+dy[k];
				if(0<=xx && xx<w && 0<=yy && yy<h && B[yy][xx]!='#' && d[yy][xx]==-1){
					if(B[yy][xx]=='g' || (B[yy][xx]-'0')*pow(0.99,d[y][x]+1)>mi){
						d[yy][xx]=d[y][x]+1;
						Q.emplace(xx,yy);
					}
				}
			}
		}

		if(d[gy][gx]!=-1) lo=mi;
		else              hi=mi;
	}

	cout<<setprecision(15)<<lo<<'\n';

	return 0;
}
