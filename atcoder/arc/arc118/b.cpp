#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint k,n,m; scanf("%lld%lld%lld",&k,&n,&m);
	vector<lint> a(k);
	rep(i,k) scanf("%lld",&a[i]);

	vector<lint> ans(k);
	lint lo=-1,hi=n*m;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		vector<lint> l(k),r(k);
		rep(i,k){
			l[i]=(m*a[i]-mi+n-1)/n;
			r[i]=(m*a[i]+mi)/n;
		}

		lint lsum=accumulate(l.begin(),l.end(),0LL);
		lint rsum=accumulate(r.begin(),r.end(),0LL);
		if(lsum<=m && m<=rsum){
			hi=mi;
			lint sum=lsum;
			rep(i,k){
				ans[i]=min(l[i]+m-sum,r[i]);
				sum+=ans[i]-l[i];
			}
		}
		else lo=mi;
	}
	rep(i,k) printf("%lld%c",ans[i],i<k-1?' ':'\n');

	return 0;
}
