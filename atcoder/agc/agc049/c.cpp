#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	lint ans=INF,mn=INF,k=0;
	for(int i=n-1;i>=0;i--){
		if(b[i]>=a[i]){ // 危険
			ans=min(ans,max(b[i]-a[i]+1,k));
			if(a[i]<mn){
				k++;
			}
		}
		else{ // 安全
			mn=min(mn,a[i]-b[i]);
		}
	}
	ans=min(ans,k);
	printf("%lld\n",ans);

	return 0;
}
