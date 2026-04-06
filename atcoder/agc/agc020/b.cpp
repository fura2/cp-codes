#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int k; scanf("%d",&k);
	vector<lint> a(k);
	rep(i,k) scanf("%lld",&a[i]);

	lint mn=2,mx=2;
	for(int i=k-1;i>=0;i--){
		mn=(mn+a[i]-1)/a[i]*a[i];
		mx=mx/a[i]*a[i]+(a[i]-1);
		if(mn>mx) return puts("-1"),0;
	}
	printf("%lld %lld\n",mn,mx);

	return 0;
}
