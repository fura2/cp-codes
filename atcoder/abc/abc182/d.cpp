#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	lint ans=0,pos=0;
	lint mx=0,d=0;
	rep(i,n){
		d+=a[i];
		mx=max(mx,d);
		ans=max(ans,pos+mx);
		pos+=d;
	}
	printf("%lld\n",ans);

	return 0;
}
