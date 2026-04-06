#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x1,y1,r; scanf("%d%d%d",&x1,&y1,&r);
	int x2,y2,x3,y3; scanf("%d%d%d%d",&x2,&y2,&x3,&y3);
	puts(x2<=x1-r&&x1+r<=x3&&y2<=y1-r&&y1+r<=y3?"NO":"YES");
	puts((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)<=r*r
	   &&(x2-x1)*(x2-x1)+(y3-y1)*(y3-y1)<=r*r
	   &&(x3-x1)*(x3-x1)+(y2-y1)*(y2-y1)<=r*r
	   &&(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)<=r*r?"NO":"YES");
	return 0;
}
