#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	lint sum1=0,sum2=0;
	rep(i,n){
		sum1+=a[i];
		sum2+=a[i]*a[i];
	}
	printf("%lld\n",n*sum2-sum1*sum1);

	return 0;
}
