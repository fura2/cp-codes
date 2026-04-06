#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,a; scanf("%d%d",&n,&a);
	int x[50];
	rep(i,n) scanf("%d",&x[i]);

	lint dp[51][2501]={};
	dp[0][0]=1;
	rep(k,n){
		for(int i=n;i>0;i--) for(int w=2500;w>=x[k];w--) dp[i][w]+=dp[i-1][w-x[k]];
	}

	lint ans=0;
	rep(i,n) ans+=dp[i+1][(i+1)*a];
	printf("%lld\n",ans);

	return 0;
}
