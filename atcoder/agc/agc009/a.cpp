#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	lint cnt=0;
	for(int i=n-1;i>=0;i--){
		cnt+=(b[i]-(a[i]+cnt)%b[i])%b[i];
	}
	printf("%lld\n",cnt);

	return 0;
}
