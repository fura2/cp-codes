#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);

	lint ans=0;
	for(int a=1;a<=n;a++) for(int b=1;a*b<=n;b++) {
		int c=n-a*b;
		if(c>0) ans++;
	}
	printf("%lld\n",ans);

	return 0;
}
