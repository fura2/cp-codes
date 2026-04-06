#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);

	int d;
	if     (a==b) d=c;
	else if(a==c) d=b;
	else          d=a;
	printf("%d\n",d);

	return 0;
}
