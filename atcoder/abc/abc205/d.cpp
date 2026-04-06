#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	rep(_,q){
		lint k; scanf("%lld",&k);
		lint lo=0,hi=2e18;
		while(hi-lo>1){
			lint mi=(lo+hi)/2;
			if(mi-(upper_bound(a.begin(),a.end(),mi)-a.begin())>=k) hi=mi; else lo=mi;
		}
		printf("%lld\n",hi);
	}

	return 0;
}
