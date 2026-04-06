#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	lint n,h,a,b,c,d,e;
	scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&h,&a,&b,&c,&d,&e);

	lint ans=INF;
	rep(i,n+1){
		lint r=h-i*e;
		if((n-i)*b+r<=0) continue;
		if((n-i)*d+r>0){
			ans=min(ans,(n-i)*c);
		}
		else{
			lint k=-((n-i)*d+r)/(b-d)+1;
			ans=min(ans,(n-i-k)*c+k*a);
		}
	}
	printf("%lld\n",ans);

	return 0;
}
