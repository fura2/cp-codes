#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	lint mx=0,sum=0;
	rep(i,n){
		mx=max(mx,a[i]);
		sum+=cum[i+1];
		printf("%lld\n",sum+(i+1)*mx);
	}

	return 0;
}
