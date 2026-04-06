#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

int main(){
	int n; cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];

	vector<lint> sum(n+1);
	rep(i,n) sum[i+1]=sum[i]+a[i];

	lint ans=INF;
	rep(i,n-1) ans=min(ans,abs(sum[i+1]-(sum[n]-sum[i+1])));
	cout<<ans<<endl;

	return 0;
}
