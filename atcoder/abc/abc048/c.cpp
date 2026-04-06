#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	lint ans=0;
	rep(i,n-1) if(a[i]+a[i+1]>x) {
		ans+=a[i]+a[i+1]-x;
		a[i+1]=x-a[i];
		if(a[i+1]<0){
			a[i]+=a[i+1];
			a[i+1]=0;
		}
	}
	printf("%lld\n",ans);

	return 0;
}
