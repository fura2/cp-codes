#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.rbegin(),a.rend());

	lint ans=a[0];
	rep(i,n-2) ans+=a[i/2+1];
	printf("%lld\n",ans);

	return 0;
}
