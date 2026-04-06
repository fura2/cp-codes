#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	map<int,int> f;
	rep(i,n){
		int a; scanf("%d",&a);
		++f[a];
	}

	lint ans=n*(n-1LL)/2;
	for(auto [_,x]:f) ans-=x*(x-1LL)/2;
	printf("%lld\n",ans);

	return 0;
}
