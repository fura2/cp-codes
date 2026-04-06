#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	lint ans=0,sum=0;
	for(int i=n-1;i>=0;i--){
		ans+=sum-(n-1-i)*a[i];
		sum+=a[i];
	}
	printf("%lld\n",ans);

	return 0;
}
