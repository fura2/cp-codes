#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int k;
	for(k=0;(1<<k)<n;k++);
	if((1<<k)==n){
		puts("No");
		return 0;
	}

	puts("Yes");
	int r=n%4;
	if(r==3){
		rep(i,2*n-1) printf("%d %d\n",i+1,i+2);
	}
	else if(r==1){
		rep(i,n-3) printf("%d %d\n",i+1,i+2);
		printf("%d %d\n",n-2,n+1);
		rep(i,n-3) printf("%d %d\n",n+i+1,n+i+2);
		printf("%d %d\n",1,n-1);
		printf("%d %d\n",n-1,n);
		printf("%d %d\n",1,2*n);
		printf("%d %d\n",2*n,2*n-1);
	}
	else if(r==2){
		rep(i,n-4) printf("%d %d\n",i+1,i+2);
		printf("%d %d\n",n-3,n+1);
		rep(i,n-4) printf("%d %d\n",n+i+1,n+i+2);
		printf("%d %d\n",1,n-2);
		printf("%d %d\n",n-2,n-1);
		printf("%d %d\n",1,2*n-1);
		printf("%d %d\n",2*n-1,2*n-2);
		printf("%d %d\n",2,n);
		printf("%d %d\n",2*n-1,2*n);
	}
	else{ // r==0
		rep(i,n-2) printf("%d %d\n",i+1,i+2);
		printf("%d %d\n",n-1,n+1);
		rep(i,n-2) printf("%d %d\n",n+i+1,n+i+2);

		int x=0,i;
		for(i=1<<(k-1);;i--){
			x^=i;
			if(x==n) break;
		}
		printf("%d %d\n",1<<(k-1),n);
		printf("%d %d\n",i,2*n);
	}

	return 0;
}
