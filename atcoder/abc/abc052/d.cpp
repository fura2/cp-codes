#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint a,b; scanf("%d%lld%lld",&n,&a,&b);
	vector<int> x(n);
	rep(i,n) scanf("%d",&x[i]);

	lint ans=0;
	rep(i,n-1) ans+=min(a*(x[i+1]-x[i]),b);
	printf("%lld\n",ans);

	return 0;
}
