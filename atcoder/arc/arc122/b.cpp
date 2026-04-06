#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<double> a(n);
	rep(i,n) scanf("%lf",&a[i]);

	sort(a.begin(),a.end());

	vector<double> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	double ans=cum[n];
	rep(i,n){
		double x=a[i]/2;
		ans=min(ans,n*x+cum[n]-(2*(n-i-1)*x+cum[i+1]));
	}
	ans/=n;
	printf("%.9f\n",ans);

	return 0;
}
