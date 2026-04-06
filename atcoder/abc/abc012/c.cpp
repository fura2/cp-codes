#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	for(int a=1;a<=9;a++) for(int b=1;b<=9;b++) if(a*b+n==2025) printf("%d x %d\n",a,b);
	return 0;
}
