#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	lint ans=0;
	rep(i,n+1) if(i%3!=0 && i%5!=0) ans+=i;
	printf("%lld\n",ans);
	return 0;
}
