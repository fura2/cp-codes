#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,m,vote,p; scanf("%lld%lld%lld%lld",&n,&m,&vote,&p);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sort(a.begin(),a.end(),greater<int>());

	int lo=0,hi=n;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		lint tar=a[mi]+m,k=m*vote;
		k-=m*(n-mi);
		k-=m*(p-1);
		if(k<=0){
			if(tar>=a[p-1]) lo=mi;
			else            hi=mi;
			continue;
		}

		bool ok=true;
		for(int i=p-1;i<mi;i++){
			if(a[i]>tar) ok=false;
			k-=min(tar-a[i],m);
		}
		if(ok && k<=0) lo=mi;
		else           hi=mi;
	}

	printf("%d\n",hi);

	return 0;
}
