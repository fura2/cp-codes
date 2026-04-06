#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int t;
	lint n; scanf("%d%lld",&t,&n);

	lint lo=0,hi=1e12;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		// maximum a s.t. floor((100+t)*a/100) <= mi
		lint a=100*mi/(100+t);
		if((100+t)*(a+1)/100<=mi) a++;

		if(mi-a>=n) hi=mi;
		else        lo=mi;
	}
	printf("%lld\n",hi);

	return 0;
}
