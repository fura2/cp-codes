#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k,n; scanf("%d%d",&k,&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int mx=k-a[n-1]+a[0];
	rep(i,n-1) mx=max(mx,a[i+1]-a[i]);
	printf("%d\n",k-mx);

	return 0;
}
