#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;
const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	int h,w,n; cin>>h>>w>>n;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int sx,sy;
	rep(i,h) rep(j,w) if(B[i][j]=='S') {
		B[i][j]='.';
		sx=i;
		sy=j;
	}

	vector d(h,vector(w,INF));
	d[sx][sy]=0;
	queue<pair<int,int>> Q; Q.emplace(sx,sy);
	while(!Q.empty()){
		int x,y;
		tie(x,y)=Q.front(); Q.pop();

		rep(k,4){
			int x2=x+dx[k],y2=y+dy[k];
			if(0<=x2 && x2<h && 0<=y2 && y2<w && B[x2][y2]=='.' && d[x2][y2]==INF){
				d[x2][y2]=d[x][y]+1;
				Q.emplace(x2,y2);
			}
		}
	}

	int ans=INF;
	rep(i,h) rep(j,w) if(d[i][j]<=n) ans=min(ans,1+(min({i,j,h-i-1,w-j-1})+n-1)/n);
	printf("%d\n",ans);

	return 0;
}
