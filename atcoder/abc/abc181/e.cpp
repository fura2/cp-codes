#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<lint> x(n),a(m);
	rep(i,n) scanf("%lld",&x[i]);
	rep(j,m) scanf("%lld",&a[j]);

	sort(x.begin(),x.end());
	sort(a.begin(),a.end());

	if(n==1){
		lint ans=INF;
		rep(j,m) ans=min(ans,abs(x[0]-a[j]));
		printf("%lld\n",ans);
		return 0;
	}

	vector<lint> L(n),R(n);
	L[1]=x[1]-x[0];
	R[n-2]=x[n-1]-x[n-2];
	for(int i=3;i<n;i+=2){
		L[i]=L[i-2]+x[i]-x[i-1];
	}
	for(int i=n-4;i>=0;i-=2){
		R[i]=R[i+2]+x[i+1]-x[i];
	}

	lint ans=INF;
	rep(j,m){
		int idx=lower_bound(x.begin(),x.end(),a[j])-x.begin();
		if(idx%2==0){
			ans=min(ans,(idx>=1?L[idx-1]:0)+x[idx]-a[j]+(idx+1<n?R[idx+1]:0));
		}
		else{
			ans=min(ans,(idx>=2?L[idx-2]:0)+a[j]-x[idx-1]+(idx<n?R[idx]:0));
		}
	}
	printf("%lld\n",ans);

	return 0;
}
