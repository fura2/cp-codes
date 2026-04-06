#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	priority_queue<lint,vector<lint>,greater<>> Q;
	lint unif=0;
	int q; scanf("%d",&q);
	rep(_,q){
		int type; scanf("%d",&type);
		if(type==1){
			lint x; scanf("%lld",&x);
			Q.emplace(x-unif);
		}
		else if(type==2){
			lint x; scanf("%lld",&x);
			unif+=x;
		}
		else{
			lint x=Q.top();
			Q.pop();
			printf("%lld\n",x+unif);
		}
	}

	return 0;
}
