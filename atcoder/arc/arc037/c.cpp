#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,k; scanf("%lld%lld",&n,&k);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	sort(b.begin(),b.end());

	lint lo=0,hi=1e18;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		lint cnt=0;
		rep(i,n){
			cnt+=upper_bound(b.begin(),b.end(),mi/a[i])-b.begin();
		}
		if(cnt<k) lo=mi;
		else      hi=mi;
	}
	printf("%lld\n",hi);

	return 0;
}
