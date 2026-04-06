#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,k; scanf("%lld%lld",&n,&k);
	n%=k;
	printf("%lld\n",min(n,k-n));
	return 0;
}
