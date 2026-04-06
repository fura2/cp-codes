#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<pair<lint,lint>> p(n);
	rep(i,n) scanf("%lld%lld",&p[i].first,&p[i].second);

	sort(p.begin(),p.end());

	lint x=k;
	for(auto [a,b]:p) if(x>=a) x+=b;
	printf("%lld\n",x);

	return 0;
}
