#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[3];
	rep(i,3) scanf("%d",&a[i]);

	sort(a,a+3);

	puts(a[0]==5&&a[1]==5&&a[2]==7?"YES":"NO");

	return 0;
}
