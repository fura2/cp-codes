#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[4][4];
	rep(i,4) rep(j,4) scanf("%d",&a[i][j]);

	rep(i,4) rep(j,4) {
		if(i<3 && a[i][j]==a[i+1][j]) return puts("CONTINUE"),0;
		if(j<3 && a[i][j]==a[i][j+1]) return puts("CONTINUE"),0;
	}
	puts("GAMEOVER");

	return 0;
}
