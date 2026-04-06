#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);

	lint ans=0,t=1;
	rep(i,6){
		ans+=i*max(min(1000*t-1,n)-t+1,0LL);
		t*=1000;
	}
	printf("%lld\n",ans);

	return 0;
}
