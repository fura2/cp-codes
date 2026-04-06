#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int k,n; scanf("%d%d",&k,&n);
	vector<lint> a(n),d(n);
	rep(i,n) scanf("%lld%lld",&a[i],&d[i]);

	lint lo=0,hi=1e12;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		lint cnt=0;
		rep(i,n) if(mi>=a[i]) cnt+=(mi-a[i])/d[i]+1;
		if(cnt<k) lo=mi;
		else      hi=mi;
	}

	lint ans=0;
	rep(i,n) if(lo>=a[i]) {
		lint m=(lo-a[i])/d[i]+1;
		ans+=m*a[i]+m*(m-1)/2*d[i];
		a[i]+=m*d[i];
		k-=m;
	}
	ans+=*min_element(a.begin(),a.end())*k;
	printf("%lld\n",ans);

	return 0;
}
