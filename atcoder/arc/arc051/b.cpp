#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k; scanf("%d",&k);
	int a=0,b=1;
	rep(i,k){
		a+=b;
		swap(a,b);
	}
	printf("%d %d\n",a,b);
	return 0;
}
