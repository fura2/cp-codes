#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	if(accumulate(a.begin(),a.end(),0LL)==x) return printf("%d\n",n),0;

	sort(a.begin(),a.end());

	lint sum=0;
	rep(i,n){
		sum+=a[i];
		if(sum>x) return printf("%d\n",i),0;
	}
	printf("%d\n",n-1);

	return 0;
}
