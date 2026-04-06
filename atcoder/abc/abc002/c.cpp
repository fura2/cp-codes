#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x[3],y[3];
	rep(i,3) scanf("%d%d",x+i,y+i);
	rep(i,2) x[i]-=x[2], y[i]-=y[2];
	printf("%.9f\n",abs(x[0]*y[1]-x[1]*y[0])/2.0);

	return 0;
}
