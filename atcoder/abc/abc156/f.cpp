#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int k,q; scanf("%d%d",&k,&q);
	vector<lint> d0(k);
	rep(i,k) scanf("%lld",&d0[i]);

	rep(_,q){
		lint n,x,m; scanf("%lld%lld%lld",&n,&x,&m);

		vector<lint> d(k);
		rep(i,k) d[i]=d0[i]%m;

		lint res0=0;
		res0+=count(d.begin(),d.end(),0)*((n-1)/k);
		res0+=count(d.begin(),d.begin()+(n-1)%k,0);

		lint last=x;
		last+=accumulate(d.begin(),d.end(),0LL)*((n-1)/k);
		last+=accumulate(d.begin(),d.begin()+(n-1)%k,0LL);
		lint res1=last/m-x/m;

		printf("%lld\n",(n-1)-res0-res1);
	}

	return 0;
}
