#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);

	lint a=1,b=1;
	rep(i,n){
		lint l,r; scanf("%lld%lld",&l,&r);

		lint a2,b2;
		a2=(a+l-1)/l*l;
		b2=a2/l*r;
		if(b2>=b){
			a=a2;
			b=b2;
			continue;
		}

		b2=(b+r-1)/r*r;
		a2=b2/r*l;
		if(a2>=a){
			a=a2;
			b=b2;
		}
	}
	printf("%lld\n",a+b);

	return 0;
}
