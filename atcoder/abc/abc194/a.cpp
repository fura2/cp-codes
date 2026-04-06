#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	if     (a+b>=15 && b>=8) puts("1");
	else if(a+b>=10 && b>=3) puts("2");
	else if(a+b>=3) puts("3");
	else puts("4");
	return 0;
}
