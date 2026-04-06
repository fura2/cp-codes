#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,1,0,-1,-1,-1,0,1};
const int dy[]={0,-1,-1,-1,0,1,1,1};

int main(){
	string pttn[12][5];
	rep(k,12) rep(i,5) pttn[k][i]="?????";

	pttn[0][0]="..o..";
	pttn[0][1]=".o.o.";
	pttn[0][2]="o...o";
	pttn[0][3]="ooooo";
	pttn[0][4]="o...o";

	pttn[1][0]="oooo.";
	pttn[1][1]="o...o";
	pttn[1][2]="oooo.";
	pttn[1][3]="o...o";
	pttn[1][4]="oooo.";

	pttn[2][0]=".ooo.";
	pttn[2][1]="o...o";
	pttn[2][2]="o....";
	pttn[2][3]="o...o";
	pttn[2][4]=".ooo.";

	rep(d,3) rep(k,3) rep(i,5) rep(j,5) pttn[3*(d+1)+k][4-j][i]=pttn[3*d+k][i][j];

	int h,w; cin>>h>>w;
	string B[1000];
	rep(i,h) cin>>B[i];

	int ans[3]={};
	bool vis[1000][1000]={};
	rep(i,h) rep(j,w) if(B[i][j]=='o' && !vis[i][j]) {
		vis[i][j]=true;

		int x_min=w,x_max=0,y_min=h,y_max=0;
		queue<pair<int,int>> Q;
		Q.emplace(i,j);
		while(!Q.empty()){
			int y,x; tie(y,x)=Q.front(); Q.pop();
			x_min=min(x_min,x); x_max=max(x_max,x);
			y_min=min(y_min,y); y_max=max(y_max,y);
			rep(k,8){
				int y2=y+dy[k],x2=x+dx[k];
				if(0<=y2 && y2<h && 0<=x2 && x2<w && B[y2][x2]=='o' && !vis[y2][x2]){
					vis[y2][x2]=true;
					Q.emplace(y2,x2);
				}
			}
		}

		int r=(x_max-x_min+1)/5;
		string Z[5];
		rep(y,5){
			Z[y]="?????";
			rep(x,5) Z[y][x]=B[y_min+r*y][x_min+r*x];
		}
		rep(k,12){
			bool ok=true;
			rep(y,5) if(Z[y]!=pttn[k][y]) { ok=false; break; }
			if(ok) ans[k%3]++;
		}
	}

	rep(i,3) printf("%d%c",ans[i],i<2?' ':'\n');

	return 0;
}
