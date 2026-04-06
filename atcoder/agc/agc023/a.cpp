#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);

	vector<lint> sum(n+1);
	rep(i,n){
		int a; scanf("%d",&a);
		sum[i+1]=sum[i]+a;
	}

	map<lint,int> f;
	rep(i,n+1) ++f[sum[i]];

	lint ans=0;
	rep(i,n){
		ans+=--f[sum[i]];
	}
	printf("%lld\n",ans);

	return 0;
}
