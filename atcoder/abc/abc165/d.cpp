#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,n; cin>>a>>b>>n;
	lint x=min(n,b-1);
	printf("%lld\n",(a*x)/b-a*(x/b));
	return 0;
}
