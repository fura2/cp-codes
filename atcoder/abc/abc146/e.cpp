#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]), a[i]--;

	vector<lint> sum(n+1);
	rep(i,n) sum[i+1]=(sum[i]+a[i])%k;

	map<lint,int> f;
	rep(i,min(n+1,k)) ++f[sum[i]];

	lint ans=0;
	rep(i,n){
		--f[sum[i]];
		ans+=f[sum[i]];
		if(k+i<=n) ++f[sum[k+i]];
	}
	printf("%lld\n",ans);

	return 0;
}
