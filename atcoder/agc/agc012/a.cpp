#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(3*n);
	rep(i,3*n) scanf("%d",&a[i]);

	sort(a.rbegin(),a.rend());

	lint ans=0;
	rep(i,n) ans+=a[2*i+1];
	printf("%lld\n",ans);

	return 0;
}
