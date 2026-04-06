#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);
	vector<pair<int,int>> E(n-1);
	rep(i,n-1) scanf("%d%d",&E[i].first,&E[i].second), E[i].first--, E[i].second--;

	lint ans=n*(n+1)*(n+2)/6;
	rep(i,n-1){
		auto [u,v]=E[i];
		if(u>v) swap(u,v);
		ans-=(u+1LL)*(n-v);
	}
	printf("%lld\n",ans);

	return 0;
}
