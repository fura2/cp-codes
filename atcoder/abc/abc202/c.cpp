#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n),c(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;
	rep(i,n) scanf("%d",&b[i]), b[i]--;
	rep(i,n) scanf("%d",&c[i]), c[i]--;

	vector<int> hist(n);
	rep(i,n) hist[a[i]]++;

	lint ans=0;
	rep(i,n) ans+=hist[b[c[i]]];
	printf("%lld\n",ans);

	return 0;
}
