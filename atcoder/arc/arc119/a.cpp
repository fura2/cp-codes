#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	lint n; scanf("%lld",&n);

	lint ans=INF;
	for(lint b=0;b<=60;b++){
		lint a=n/(1LL<<b);
		lint c=n%(1LL<<b);
		ans=min(ans,a+b+c);
	}
	printf("%lld\n",ans);

	return 0;
}
