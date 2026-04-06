#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	lint ans=0;
	rep(i,n){
		ans+=a[i]/2;
		a[i]%=2;
		if(i<n-1){
			int c=min(a[i],a[i+1]);
			ans+=c;
			a[ i ]-=c;
			a[i+1]-=c;
		}
	}
	printf("%lld\n",ans);

	return 0;
}
