#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	n=108*n/100;
	puts(n<206?"Yay!":n==206?"so-so":":(");
	return 0;
}
