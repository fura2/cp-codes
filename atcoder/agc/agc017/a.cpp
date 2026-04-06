#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,p; scanf("%d%d",&n,&p);

	int odd=0;
	rep(i,n){
		int a; scanf("%d",&a);
		if(a%2) odd++;
	}

	lint ans;
	if(odd==0) ans=(p==1?0:1LL<<n);
	else       ans=1LL<<(n-1);
	printf("%lld\n",ans);

	return 0;
}
