#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int h,w;
vector<string> B;

bool vis[2000][2000][2];
int memo[2000][2000][2];

int dfs(int i,int j,int turn){
	if(i==h-1 && j==w-1) return 0;

	int& res=memo[i][j][turn];
	if(vis[i][j][turn]) return res;
	vis[i][j][turn]=true;

	if(turn==0){
		res=-INF;
		if(i<h-1) res=max(res,dfs(i+1,j,1-turn)+(B[i+1][j]=='+'?1:-1));
		if(j<w-1) res=max(res,dfs(i,j+1,1-turn)+(B[i][j+1]=='+'?1:-1));
	}
	else{
		res=INF;
		if(i<h-1) res=min(res,dfs(i+1,j,1-turn)-(B[i+1][j]=='+'?1:-1));
		if(j<w-1) res=min(res,dfs(i,j+1,1-turn)-(B[i][j+1]=='+'?1:-1));
	}
	return res;
}

int main(){
	cin>>h>>w;
	B.resize(h);
	rep(i,h) cin>>B[i];

	int res=dfs(0,0,0);
	puts(res>0?"Takahashi":res==0?"Draw":"Aoki");

	return 0;
}
