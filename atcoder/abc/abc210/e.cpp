#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n;
	int m; scanf("%lld%d",&n,&m);
	vector<lint> a(m),c(m);
	rep(i,m) scanf("%lld%lld",&a[i],&c[i]);

	vector<int> p(m);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return c[i]<c[j];
	});

	lint ans=0,x=n;
	for(int i:p){
		lint x2=gcd(a[i],x);
		ans+=(x-x2)*c[i];
		x=x2;
	}
	printf("%lld\n",x==1?ans:-1);

	return 0;
}
