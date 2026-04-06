#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	x*=100;
	rep(i,n){
		int v,p; scanf("%d%d",&v,&p);
		x-=v*p;
		if(x<0){
			printf("%d\n",i+1);
			return 0;
		}
	}
	puts("-1");

	return 0;
}
