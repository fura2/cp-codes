#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	int x[100000];
	rep(i,n) scanf("%d",x+i);

	lint ans=INF;
	rep(i,n-k+1){
		lint l=x[i],r=x[k+i-1];
		if(r<=0){
			ans=min(ans,-l);
		}
		else if(0<=l){
			ans=min(ans,r);
		}
		else{
			ans=min({ans,r-2*l,2*r-l});
		}
	}
	printf("%d\n",ans);

	return 0;
}
