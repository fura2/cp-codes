#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,m; scanf("%lld%lld",&n,&m);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	vector<lint> sum(n+1);
	rep(i,n) sum[i+1]=sum[i]+a[i];

	lint lo=0,hi=2e5+1;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		lint tmp=0;
		rep(i,n){
			tmp+=a.end()-lower_bound(a.begin(),a.end(),mi-a[i]);
		}
		if(tmp>=m) lo=mi;
		else       hi=mi;
	}

	lint ans=0;
	rep(i,n){
		int idx=lower_bound(a.begin(),a.end(),hi-a[i])-a.begin();
		m-=n-idx;
		ans+=(n-idx)*a[i]+(sum[n]-sum[idx]);
	}
	ans+=m*lo;

	printf("%lld\n",ans);

	return 0;
}
