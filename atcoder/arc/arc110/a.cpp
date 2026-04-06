#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);

	lint x=1;
	for(lint i=2;i<=n;i++) x=lcm(x,i);
	printf("%lld\n",x+1);

	return 0;
}
