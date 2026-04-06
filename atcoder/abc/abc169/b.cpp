#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	if(count(a.begin(),a.end(),0)>0) return puts("0"),0;

	lint ans=1;
	rep(i,n){
		if(ans>1000000000000000000LL/a[i]) return puts("-1"),0;
		ans*=a[i];
	}
	printf("%lld\n",ans);

	return 0;
}
