#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double INF=1e77;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int cost[4];
	double p[4][10]={};
	rep(i,m){
		int c; scanf("%d%d",&c,&cost[i]);
		rep(j,c){
			int id,q; scanf("%d%d",&id,&q); id--;
			p[i][id]=q/100.0;
		}
	}

	double dp[1<<10]={};
	for(int S=(1<<n)-2;S>=0;S--){
		dp[S]=INF;
		rep(i,m){
			double tmp=0,q=0;
			rep(j,n){
				if(S>>j&1) q+=p[i][j];
				else       tmp+=p[i][j]*dp[S|(1<<j)];
			}
			if(q<0.999) dp[S]=min(dp[S],(tmp+cost[i])/(1-q));;
		}
	}
	printf("%.9f\n",dp[0]);

	return 0;
}
