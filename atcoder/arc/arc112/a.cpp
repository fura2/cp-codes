#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

void solve(){
	lint l,r; scanf("%lld%lld",&l,&r);
	printf("%lld\n",r-2*l>=0?(r-2*l+1)*(r-2*l+2)/2:0);
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
