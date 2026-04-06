#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n=10;
	printf("%d\n",n*n*n);
	rep(i,n) rep(j,n) rep(k,n) {
		int x=j*n+k;
		int y=i*200+j*n;
		printf("%d %d\n",x,y);
	}
	return 0;
}
