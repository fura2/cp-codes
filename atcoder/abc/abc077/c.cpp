#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n),c(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);
	rep(i,n) scanf("%d",&c[i]);

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());

	vector<lint> dp1(n+1),dp2(n);
	rep(i,n){
		dp1[i+1]=dp1[i]+(lower_bound(a.begin(),a.end(),b[i])-a.begin());
	}
	rep(i,n){
		dp2[i]=dp1[lower_bound(b.begin(),b.end(),c[i])-b.begin()];
	}
	cout<<accumulate(dp2.begin(),dp2.end(),0LL)<<'\n';

	return 0;
}
