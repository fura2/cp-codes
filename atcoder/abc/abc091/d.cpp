#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	vector<lint> b2[30];
	rep(i,30){
		b2[i]=b;
		rep(j,n) b2[i][j]&=(1LL<<(i+1))-1;
		sort(b2[i].begin(),b2[i].end());
	}

	int ans=0;
	rep(i,30){
		lint cnt=0;
		rep(j,n){
			lint a2=a[j]&((1LL<<(i+1))-1);
			cnt+=lower_bound(b2[i].begin(),b2[i].end(),(1LL<<(i+1))-a2)
				-lower_bound(b2[i].begin(),b2[i].end(),(1LL<<i)-a2);
			cnt+=lower_bound(b2[i].begin(),b2[i].end(),(1LL<<(i+2))-a2)
				-lower_bound(b2[i].begin(),b2[i].end(),(1LL<<(i+1))+(1LL<<i)-a2);
		}
		if(cnt%2==1) ans|=1<<i;
	}
	printf("%d\n",ans);

	return 0;
}
