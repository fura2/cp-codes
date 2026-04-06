#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	lint x=0;
	for(int i=2;i<n;i++) x^=a[i];

	if(a[0]+a[1]<x || (a[0]+a[1]-x)%2!=0) return puts("-1"),0;

	lint y=(a[0]+a[1]-x)/2;
	if((~x&y)!=y || a[0]<y) return puts("-1"),0;

	// maximize r s.t. r & ~x = y, r <= a[0]
	lint res=y;
	for(int i=60;i>=0;i--) if((x>>i&1)==1) {
		if((res|(1LL<<i))<=a[0]) res|=1LL<<i;
	}
	printf("%lld\n",res==0?-1:a[0]-res);

	return 0;
}
