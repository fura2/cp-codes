#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int m=0,sum=0;
	rep(i,n){
		int a; scanf("%d",&a);
		if(a>0) m++, sum+=a;
	}
	printf("%d\n",(sum+m-1)/m);
	return 0;
}
