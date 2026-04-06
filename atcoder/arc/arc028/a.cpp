#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b);
	n%=a+b;
	puts(1<=n&&n<=a?"Ant":"Bug");
	return 0;
}
