#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n;
	lint x; scanf("%d%lld",&n,&x);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> cost(n,INF);

	lint ans=INF;
	rep(t,n){
		rep(i,n) cost[i]=min(cost[i],a[(i-t+n)%n]);
		ans=min(ans,t*x+accumulate(cost.begin(),cost.end(),0LL));
	}
	printf("%lld\n",ans);

	return 0;
}
