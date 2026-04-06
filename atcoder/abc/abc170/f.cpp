#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
const int INF=1<<29;

int main(){
	int h,w,k; cin>>h>>w>>k;
	int sy,sx,gy,gx; cin>>sy>>sx>>gy>>gx; sy--; sx--; gy--; gx--;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector d(h,vector(w,INF));
	d[sy][sx]=0;
	queue<pair<int,int>> Q;
	Q.emplace(sy,sx);
	while(!Q.empty()){
		int y,x; tie(y,x)=Q.front(); Q.pop();
		rep(dir,4){
			int y2=y,x2=x;
			rep(_,k){
				y2+=dy[dir];
				x2+=dx[dir];
				if(y2<0 || h<=y2 || x2<0 || w<=x2 || B[y2][x2]=='@' || d[y2][x2]<=d[y][x]) break;
				if(d[y2][x2]>d[y][x]+1){
					d[y2][x2]=d[y][x]+1;
					Q.emplace(y2,x2);
				}
			}
		}
	}

	printf("%d\n",d[gy][gx]<INF?d[gy][gx]:-1);

	return 0;
}
