#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,k; scanf("%lld%lld",&n,&k);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	sort(a.begin(),a.end());
	sort(b.rbegin(),b.rend());

	lint lo=-1,hi=1e14;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		lint cost=0;
		rep(i,n){
			cost+=max(a[i]-mi/b[i],0LL);
		}
		if(cost<=k) hi=mi;
		else        lo=mi;
	}
	cout<<hi<<endl;

	return 0;
}
