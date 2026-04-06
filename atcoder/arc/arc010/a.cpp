#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,a,b; scanf("%d%d%d%d",&n,&m,&a,&b);
	rep(i,m){
		int c; scanf("%d",&c);
		if(n<=a) n+=b;
		n-=c;
		if(n<0) return printf("%d\n",i+1),0;
	}
	puts("complete");

	return 0;
}
