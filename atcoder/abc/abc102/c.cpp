#include <algorithm>
#include <cmath>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a[200000];
	scanf("%d",&n);
	rep(i,n) scanf("%d",a+i), a[i]-=i+1;

	sort(a,a+n);

	long long ans=0;
	rep(i,n) ans+=abs(a[i]-a[n/2]);
	printf("%lld\n",ans);

	return 0;
}
