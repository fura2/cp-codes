#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b);
	printf("%d\n",(n-min(5,n))*a+min(5,n)*b);
	return 0;
}
