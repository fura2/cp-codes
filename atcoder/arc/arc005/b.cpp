#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y;
	string w,B[9];
	cin>>x>>y>>w; x--; y--;
	rep(i,9) cin>>B[i];

	int dx,dy;
	if     (w=="R")  dx= 1, dy= 0;
	else if(w=="L")  dx=-1, dy= 0;
	else if(w=="U")  dx= 0, dy=-1;
	else if(w=="D")  dx= 0, dy= 1;
	else if(w=="RU") dx= 1, dy=-1;
	else if(w=="RD") dx= 1, dy= 1;
	else if(w=="LU") dx=-1, dy=-1;
	else             dx=-1, dy= 1;

	rep(_,4) cout<<B[y<0?-y:y<9?y:16-y][x<0?-x:x<9?x:16-x], x+=dx, y+=dy;
	cout<<endl;

	return 0;
}
