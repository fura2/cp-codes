#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k; scanf("%d",&k);

	int a=0;
	rep(i,k){
		a=(10*a+7)%k;
		if(a==0) return printf("%d\n",i+1),0;
	}
	puts("-1");

	return 0;
}
