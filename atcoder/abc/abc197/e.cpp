#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> x(n);
	vector<int> c(n);
	rep(i,n) scanf("%lld%d",&x[i],&c[i]);

	int m;
	{
		auto C=c;
		sort(C.begin(),C.end());
		C.erase(unique(C.begin(),C.end()),C.end());
		rep(i,n) c[i]=lower_bound(C.begin(),C.end(),c[i])-C.begin()+1;
		m=C.size();
	}

	vector<lint> l(m+2,INF),r(m+2,-INF);
	l[0]=l[m+1]=0;
	r[0]=r[m+1]=0;
	rep(i,n){
		l[c[i]]=min(l[c[i]],x[i]);
		r[c[i]]=max(r[c[i]],x[i]);
	}

	vector dp(m+2,vector(2,0LL));
	rep(i,m+1){
		dp[i+1][0]=min(dp[i][0]+abs(l[i]-r[i+1])+abs(r[i+1]-l[i+1]),
					   dp[i][1]+abs(r[i]-r[i+1])+abs(r[i+1]-l[i+1]));
		dp[i+1][1]=min(dp[i][0]+abs(l[i]-l[i+1])+abs(l[i+1]-r[i+1]),
					   dp[i][1]+abs(r[i]-l[i+1])+abs(l[i+1]-r[i+1]));
	}
	printf("%lld\n",dp[m+1][0]);

	return 0;
}
