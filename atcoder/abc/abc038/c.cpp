#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	lint ans=0;
	int pre=0;
	rep(i,n) if(i==n-1 || a[i]>=a[i+1]) {
		ans+=(i-pre+1LL)*(i-pre+2)/2;
		pre=i+1;
	}
	printf("%lld\n",ans);

	return 0;
}
