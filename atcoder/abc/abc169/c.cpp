#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b1,b2; scanf("%lld%lld.%lld",&a,&b1,&b2);
	lint b=100*b1+b2;
	printf("%lld\n",a*b/100);
	return 0;
}
