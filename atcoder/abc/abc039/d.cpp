#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	char B[100][101];
	rep(i,h) scanf("%s",B[i]);

	rep(i,h) rep(j,w) {
		bool ok=true;
		for(int dy=-1;dy<=1;dy++) for(int dx=-1;dx<=1;dx++) {
			int y=i+dy,x=j+dx;
			if(0<=y && y<h && 0<=x && x<w && B[y][x]=='.') ok=false;
		}
		if(ok) B[i][j]='*';
	}

	rep(i,h) rep(j,w) if(B[i][j]=='#') {
		bool ok=false;
		for(int dy=-1;dy<=1;dy++) for(int dx=-1;dx<=1;dx++) {
			int y=i+dy,x=j+dx;
			if(0<=y && y<h && 0<=x && x<w && B[y][x]=='*') ok=true;
		}
		if(!ok) return puts("impossible"),0;
	}

	puts("possible");
	rep(i,h) rep(j,w) if(B[i][j]=='#') B[i][j]='.';
	rep(i,h) rep(j,w) if(B[i][j]=='*') B[i][j]='#';
	rep(i,h) puts(B[i]);

	return 0;
}
