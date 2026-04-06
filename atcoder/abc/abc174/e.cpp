#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int lo=0,hi=1e9;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		lint cnt;
		if(mi==0){
			cnt=INF;
		}
		else{
			cnt=0;
			rep(i,n) cnt+=(a[i]+mi-1)/mi-1;
		}

		if(cnt<=k) hi=mi;
		else       lo=mi;
	}
	printf("%d\n",hi);

	return 0;
}
