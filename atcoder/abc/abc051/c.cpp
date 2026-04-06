#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int sx,sy,tx,ty; scanf("%d%d%d%d",&sx,&sy,&tx,&ty);

	rep(i,ty-sy) putchar('U');
	rep(i,tx-sx) putchar('R');
	rep(i,ty-sy) putchar('D');
	rep(i,tx-sx) putchar('L');

	putchar('L');
	rep(i,ty-sy+1) putchar('U');
	rep(i,tx-sx+1) putchar('R');
	putchar('D');
	putchar('R');
	rep(i,ty-sy+1) putchar('D');
	rep(i,tx-sx+1) putchar('L');
	putchar('U');

	return 0;
}
