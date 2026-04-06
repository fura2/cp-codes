#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> h(n),v(n);
	rep(i,n) scanf("%lld%lld",&h[i],&v[i]);

	lint lo=0,hi=1e15;
	vector<lint> t(n);
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		rep(i,n) t[i]=(mi-h[i])/v[i]; // !! CAUTION (-1)/2 == 0
		sort(t.begin(),t.end());
		bool ok=true;
		rep(i,n) if(mi<h[i] || t[i]<i) { ok=false; break; }
		if(ok) hi=mi;
		else   lo=mi;
	}
	printf("%lld\n",hi);

	return 0;
}
