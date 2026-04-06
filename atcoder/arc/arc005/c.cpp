#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int h,w;
string B[500];

bool vis[500][500][3];

bool dfs(int i,int j,int b){
	if(B[i][j]=='g') return true;

	if(vis[i][j][b]) return false;
	vis[i][j][b]=true;

	rep(k,4){
		int y=i+dy[k],x=j+dx[k];
		if(0<=y && y<h && 0<=x && x<w){
			if(B[y][x]=='#'){
				if(b<2 && dfs(y,x,b+1)) return true;
			}
			else{
				if(dfs(y,x,b)) return true;
			}
		}
	}
	return false;
}

int main(){
	cin>>h>>w;
	rep(i,h) cin>>B[i];

	rep(i,h) rep(j,w) if(B[i][j]=='s') cout<<(dfs(i,j,0)?"YES":"NO")<<endl;

	return 0;
}
