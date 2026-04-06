#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[7],b[7];
	rep(i,7) scanf("%d",&a[i]);
	rep(i,7) scanf("%d",&b[i]);

	int ans=0;
	rep(i,7) ans+=max(a[i],b[i]);
	printf("%d\n",ans);

	return 0;
}
