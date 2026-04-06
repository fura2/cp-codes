#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,l; scanf("%d%d ",&n,&l);
	string s[20],goal;
	rep(i,l) getline(cin,s[i]);
	getline(cin,goal);

	int x=find(goal.begin(),goal.end(),'o')-goal.begin();
	for(int y=l-1;y>=0;y--){
		if     (x>  0   && s[y][x-1]=='-') x-=2;
		else if(x<2*n-2 && s[y][x+1]=='-') x+=2;
	}
	printf("%d\n",x/2+1);

	return 0;
}
