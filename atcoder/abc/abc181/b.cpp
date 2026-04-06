#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);

	lint ans=0;
	rep(i,n){
		lint a,b; scanf("%lld%lld",&a,&b);
		ans+=(a+b)*(b-a+1)/2;
	}
	printf("%lld\n",ans);

	return 0;
}
