#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint d; scanf("%d%lld",&n,&d);

	int ans=0;
	rep(i,n){
		lint x,y; scanf("%lld%lld",&x,&y);
		if(x*x+y*y<=d*d) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
