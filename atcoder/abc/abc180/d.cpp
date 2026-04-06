#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x,y,a,b; cin>>x>>y>>a>>b;

	lint ans=0;
	for(int c=0;;c++){
		ans=max(ans,c+(y-x-1)/b);
		if(x>=(y+a-1)/a) break;
		x*=a;
	}
	printf("%lld\n",ans);

	return 0;
}
