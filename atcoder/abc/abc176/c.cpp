#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	lint ans=0;
	for(int i=1;i<n;i++){
		if(a[i-1]>a[i]){
			ans+=a[i-1]-a[i];
			a[i]=a[i-1];
		}
	}
	printf("%lld\n",ans);

	return 0;
}
