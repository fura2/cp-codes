#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> x(n),y(n);
	rep(i,n) scanf("%lld%lld",&x[i],&y[i]);

	int ans=0;
	rep(i,n) rep(j,i) rep(k,j) {
		lint det=(x[j]-x[i])*(y[k]-y[i])-(y[j]-y[i])*(x[k]-x[i]);
		if(det%2==0 && det!=0) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
