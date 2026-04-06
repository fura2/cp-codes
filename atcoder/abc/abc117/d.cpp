#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint k,a[100000]; scanf("%d%lld",&n,&k);
	rep(i,n) scanf("%lld",a+i);

	lint x=0;
	bool sat=true;
	for(int i=50;i>=0;i--){
		int cnt[2]={};
		rep(j,n) cnt[a[j]>>i&1]++;
		if(cnt[0]<cnt[1]){ // put 0
			if(k>>i&1) sat=false;
		}
		else{
			if(!sat || k>>i&1){ // put 1
				x|=1LL<<i;
			}
		}
	}

	lint ans=0;
	rep(i,n) ans+=x^a[i];
	printf("%lld\n",ans);

	return 0;
}
