#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint solve(vector<lint> a){
	int n=a.size();

	vector<lint> lcum(n+1),rcum(n+1);
	rep(i,n){
		lcum[i+1]=lcum[i]+a[i];
	}
	for(int i=n;i>0;i--){
		rcum[i-1]=rcum[i]+a[i-1];
	}

	vector<lint> res(n-1);
	{
		lint tmp=0;
		rep(i,n-1){
			tmp+=lcum[n-i-1];
			tmp-=lcum[n-i-1+(i+1)/2]-lcum[n-i-1];
			res[i]+=tmp;
		}
		tmp=0;
		rep(i,n-1){
			tmp+=rcum[n-(i+1)/2];
			res[i]+=tmp;
		}
	}
	return *max_element(res.begin(),res.end());
}

int main(){
	lint l;
	int n; scanf("%lld%d",&l,&n);
	vector<lint> x(n+2);
	rep(i,n) scanf("%lld",&x[i+1]);
	x[n+1]=l;

	vector<lint> a(n+1);
	rep(i,n+1) a[i]=x[i+1]-x[i];

	lint ans=0;
	rep(_,2){
		ans=max(ans,solve(a));
		reverse(a.begin(),a.end());
	}
	printf("%lld\n",ans);

	return 0;
}
