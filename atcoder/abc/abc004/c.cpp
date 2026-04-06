#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a[]={1,2,3,4,5,6};
	scanf("%d",&n);

	n%=30;
	rep(i,n) swap(a[i%5],a[i%5+1]);

	rep(i,6) printf("%d",a[i]);
	puts("");

	return 0;
}
