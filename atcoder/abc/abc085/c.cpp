#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,y; scanf("%d%d",&n,&y);

	rep(i,n+1) rep(j,n-i+1) {
		int x=i*1000+j*5000;
		if(x<=y && (y-x)%10000==0 && (y-x)/10000==n-i-j){
			printf("%d %d %d\n",n-i-j,j,i);
			return 0;
		}
	}
	puts("-1 -1 -1");

	return 0;
}
