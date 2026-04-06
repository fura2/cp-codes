#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	char B[100][101];
	rep(i,h) scanf("%s",B[i]);

	bool win[100][100]={};
	for(int i=h-1;i>=0;i--) for(int j=w-1;j>=0;j--) if(B[i][j]=='.') {
		if(i<h-1 && B[i+1][j]=='.' && !win[i+1][j]) win[i][j]=true;
		if(j<w-1 && B[i][j+1]=='.' && !win[i][j+1]) win[i][j]=true;
		if(i<h-1 && j<w-1 && B[i+1][j+1]=='.' && !win[i+1][j+1]) win[i][j]=true;
	}
	puts(win[0][0]?"First":"Second");

	return 0;
}
