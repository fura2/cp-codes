#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<double> sum(n+1);
	rep(i,n) sum[i+1]=sum[i]+(a[i]+1)/2.0;

	double ans=0;
	rep(i,n-k+1) ans=max(ans,sum[i+k]-sum[i]);
	printf("%.9f\n",ans);

	return 0;
}
