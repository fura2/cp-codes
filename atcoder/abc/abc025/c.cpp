#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int sr[2][3],sc[3][2],total;

int dfs(string s,int turn){
	if(count(s.begin(),s.end(),'.')==0){
		int score=0;
		rep(i,2) rep(j,3) if(s[i*3+j]==s[(i+1)*3+j]) score+=sr[i][j];
		rep(i,3) rep(j,2) if(s[i*3+j]==s[i*3+(j+1)]) score+=sc[i][j];
		return turn==0?score:total-score;
	}

	int res=0;
	rep(i,3) rep(j,3) if(s[i*3+j]=='.') {
		s[i*3+j]='0'+turn;
		res=max(res,total-dfs(s,1-turn));
		s[i*3+j]='.';
	}
	return res;
}

int main(){
	rep(i,2) rep(j,3) scanf("%d",&sr[i][j]), total+=sr[i][j];
	rep(i,3) rep(j,2) scanf("%d",&sc[i][j]), total+=sc[i][j];

	int ans=dfs(".........",0);
	printf("%d\n%d\n",ans,total-ans);

	return 0;
}
