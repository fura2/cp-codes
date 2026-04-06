#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);

	lint m=(sqrt(1+8*(n+1))-1)/2+5;
	while(m*(m+1)/2>n+1) m--;

	printf("%lld\n",n-m+1);

	return 0;
}
