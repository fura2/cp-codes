#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int a[100000];
	rep(i,n) scanf("%d",a+i);

	int mx=*max_element(a,a+n),mid=0;
	rep(i,n) if(abs(2*a[i]-mx)<abs(2*mid-mx)) mid=a[i];
	printf("%d %d\n",mx,mid);

	return 0;
}
