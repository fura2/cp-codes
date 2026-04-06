#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);

	lint y0=-INF,y1=INF,b=0;
	rep(i,n){
		lint a;
		int type; scanf("%lld%d",&a,&type);
		if(type==1){
			if(y0>-INF) y0+=a;
			if(y1< INF) y1+=a;
			b+=a;
		}
		else if(type==2){
			y0=max(y0,a);
			y1=max(y1,a);
		}
		else{
			y0=min(y0,a);
			y1=min(y1,a);
		}
	}

	int q; scanf("%d",&q);
	rep(_,q){
		lint x; scanf("%lld",&x);
		printf("%lld\n",clamp(x+b,y0,y1));
	}

	return 0;
}
