#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int k;
	for(k=0;(1<<k+1)<=n;k++);

	rep(i,n){
		int x=(2*i+0)&((1<<(k+1))-1); if(x>=n) x&=(1<<k)-1;
		int y=(2*i+1)&((1<<(k+1))-1); if(y>=n) y&=(1<<k)-1;
		printf("%d %d\n",x+1,y+1);
	}

	return 0;
}
