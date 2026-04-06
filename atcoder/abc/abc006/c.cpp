#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	rep(j,n+1) if(3*j<=m) {
		int k=m-3*j;
		if(k%2==0 && n-j<=k/2 && k/2<=2*(n-j)){
			int i=2*(n-j)-k/2;
			printf("%d %d %d\n",i,j,n-i-j);
			return 0;
		}
	}
	puts("-1 -1 -1");

	return 0;
}
