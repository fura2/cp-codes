#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;
int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

vector<vector<int>> distance(vector<string> B, int sx, int sy){
	int h=B.size(),w=B[0].size();
	vector d(h,vector<int>(w,INF));
	d[sx][sy]=0;
	queue<pair<int,int>> Q;
	Q.push({sx,sy});
	while(!Q.empty()){
		auto [x,y]=Q.front(); Q.pop();
		rep(k,4){
			int x2=x+dx[k],y2=y+dy[k];
			if(0<=x2 && x2<h && 0<=y2 && y2<w && B[x2][y2]!='#' && d[x2][y2]==INF){
				d[x2][y2]=d[x][y]+1;
				Q.push({x2,y2});
			}
		}
	}
	return d;
}

int main(){
	int h,w,thre;
	cin>>h>>w>>thre;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int sx,sy,gx,gy;
	vector<int> ox,oy;
	rep(i,h) rep(j,w) {
		if(B[i][j]=='S') sx=i, sy=j;
		if(B[i][j]=='G') gx=i, gy=j;
		if(B[i][j]=='o') ox.push_back(i), oy.push_back(j);
	}
	ox.push_back(sx); oy.push_back(sy);
	ox.push_back(gx); oy.push_back(gy);

	int m=ox.size();
	int s=m-2,t=m-1;
	vector d(m,vector<int>(m));
	rep(i,m){
		auto D=distance(B,ox[i],oy[i]);
		rep(j,m) d[i][j]=D[ox[j]][oy[j]];
	}

	if(d[s][t]>thre){
		cout<<-1<<endl;
		return 0;
	}

	vector dp(1<<m,vector<int>(m,INF));
	dp[1<<s][s]=0;
	rep(S,1<<m) rep(i,m) if(S>>i&1) rep(j,m) if(~S>>j&1) {
		dp[S|1<<j][j]=min(dp[S|1<<j][j],dp[S][i]+d[i][j]);
	}

	int ans=0;
	rep(S,1<<m){
		if(dp[S][t]<=thre) ans=max(ans,popcount(S)-2);
	}
	cout<<ans<<endl;

	return 0;
}
