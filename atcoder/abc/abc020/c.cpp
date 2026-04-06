#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int h,w,T;
string B[30];

bool check(int X){
	int sx,sy;
	rep(i,h) rep(j,w) if(B[i][j]=='S') sx=j, sy=i;

	int d[30][30];
	rep(i,h) rep(j,w) d[i][j]=INT_MAX;
	d[sy][sx]=0;

	priority_queue<tuple<int,int,int>> Q;
	Q.emplace(0,sx,sy);
	while(!Q.empty()){
		auto a=Q.top(); Q.pop();
		int d0=-get<0>(a),x=get<1>(a),y=get<2>(a);
		if(d0>d[y][x]) continue;

		if(B[y][x]=='G') return true;
		rep(k,4){
			int xx=x+dx[k],yy=y+dy[k];
			if(0<=yy && yy<h && 0<=xx && xx<w){
				int dd=d0+(B[yy][xx]=='#'?X:1);
				if(dd<d[yy][xx] && dd<=T){
					d[yy][xx]=dd;
					Q.emplace(-dd,xx,yy);
				}
			}
		}
	}
	return false;
}

int main(){
	cin>>h>>w>>T;
	rep(i,h) cin>>B[i];

	int lo=0,hi=1e9;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		if(check(mi)) lo=mi;
		else          hi=mi;
	}
	cout<<lo<<endl;

	return 0;
}
