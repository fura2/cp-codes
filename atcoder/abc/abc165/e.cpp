#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	int x=m-1,y=m;
	rep(i,(m+1)/2){
		printf("%d %d\n",x+1,y+1);
		x--;
		y++;
	}
	x=0; y=n-2;
	rep(i,m/2){
		printf("%d %d\n",x+1,y+1);
		x++;
		y--;
	}

	return 0;
}
