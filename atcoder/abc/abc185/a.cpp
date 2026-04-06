#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[4];
	rep(i,4) scanf("%d",&a[i]);
	printf("%d\n",*min_element(a,a+4));
	return 0;
}
