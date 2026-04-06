#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);

	lint cnt[50][50]={};
	rep(i,n){
		double a; scanf("%lf",&a);
		lint x=1e9*a+0.5;
		int i2=0,i5=0;
		while(x%2==0) i2++, x/=2;
		while(x%5==0) i5++, x/=5;
		cnt[i2][i5]++;
	}

	lint ans=0;
	rep(i2,50) rep(i5,50) rep(j2,50) rep(j5,50) if(min(i2+j2,i5+j5)>=18) {
		ans+=cnt[i2][i5]*cnt[j2][j5];
	}
	rep(i2,50) rep(i5,50) if(min(i2,i5)>=9) ans-=cnt[i2][i5];
	ans/=2;
	printf("%lld\n",ans);

	return 0;
}
