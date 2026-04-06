#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d; scanf("%d%d",&n,&d);

	if(n==1 && d==0){
		puts("1 2");
		return 0;
	}

	if(d<0 || n-1<=d){
		puts("-1");
		return 0;
	}

	puts("1 1000000");
	rep(i,d+1) printf("%d %d\n",2*i+2,2*i+3);
	rep(i,n-d-2) printf("%d %d\n",1000000+2*i+1,1000000+2*i+2);

	return 0;
}
