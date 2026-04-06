#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n;
	lint cost; scanf("%d%lld",&n,&cost);
	vector<lint> x(n);
	rep(i,n) scanf("%lld",&x[i]);

	vector<lint> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+x[i];

	lint ans=INF;
	for(int i=1;i<=n;i++){
		long double res=(n+i)*cost+(cum[n]-cum[n-i]);
		int idx=n-1;
		for(int k=1;idx>=0;k++){
			lint dsum=(cum[idx+1]-cum[max(idx+1-i,0)])
					 -(cum[max(idx+1-i,0)]-cum[max(idx+1-2*i,0)]);
			res+=(long double)(dsum)*(k+1)*(k+1);
			idx-=i;
		}
		if(res<INF) ans=min(ans,lint(res));
	}
	printf("%lld\n",ans);

	return 0;
}
