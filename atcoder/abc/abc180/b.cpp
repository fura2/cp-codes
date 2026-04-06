#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<double> x(n);
	rep(i,n) scanf("%lf",&x[i]);

	double ans1=0,ans2=0,ans3=0;
	rep(i,n){
		ans1+=abs(x[i]);
		ans2+=x[i]*x[i];
		ans3=max(ans3,abs(x[i]));
	}
	ans2=sqrt(ans2);
	printf("%.9f\n%.9f\n%.9f\n",ans1,ans2,ans3);

	return 0;
}
