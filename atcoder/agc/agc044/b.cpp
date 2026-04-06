#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int n; scanf("%d",&n);
	vector<int> p(n*n);
	rep(i,n*n) scanf("%d",&p[i]), p[i]--;

	vector<string> B(n,string(n,'#'));
	vector<vector<int>> d(n,vector<int>(n));
	rep(i,n) rep(j,n) d[i][j]=min({i,n-1-i,j,n-1-j});

	int ans=0;
	for(int q:p){
		int i0=q/n,j0=q%n;

		B[i0][j0]='.';
		ans+=d[i0][j0];

		queue<pair<int,int>> Q; Q.emplace(i0,j0);
		while(!Q.empty()){
			int y,x; tie(y,x)=Q.front(); Q.pop();

			rep(k,4){
				int yy=y+dy[k],xx=x+dx[k];
				if(0<=yy && yy<n && 0<=xx && xx<n){
					int d2=d[y][x]+(B[y][x]=='.'?0:1);
					if(d[yy][xx]>d2){
						d[yy][xx]=d2;
						Q.emplace(yy,xx);
					}
				}
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
