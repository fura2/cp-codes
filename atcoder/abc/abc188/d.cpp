#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint C; scanf("%d%lld",&n,&C);
	vector<lint> l(n),r(n),c(n);
	rep(i,n) scanf("%lld%lld%lld",&l[i],&r[i],&c[i]), l[i]--;

	vector<lint> X;
	rep(i,n){
		X.emplace_back(l[i]);
		X.emplace_back(r[i]);
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	int m=X.size();

	rep(i,n){
		l[i]=lower_bound(X.begin(),X.end(),l[i])-X.begin();
		r[i]=lower_bound(X.begin(),X.end(),r[i])-X.begin();
	}

	vector<lint> cum(m+1);
	rep(i,n){
		cum[l[i]]+=c[i];
		cum[r[i]]-=c[i];
	}
	rep(i,m) cum[i+1]+=cum[i];

	lint ans=0;
	rep(i,m-1){
		ans+=min(cum[i],C)*(X[i+1]-X[i]);
	}
	printf("%lld\n",ans);

	return 0;
}
