#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	if(count(a.begin(),a.end(),0LL)>0) return printf("%d\n",n),0;

	int ans=0,j=0;
	lint mul=1;
	rep(i,n){
		if(j<i) j=i;
		while(j<n && mul*a[j]<=k) mul*=a[j], j++;
		if(j>i) mul/=a[i];
		ans=max(ans,j-i);
	}
	printf("%d\n",ans);

	return 0;
}
