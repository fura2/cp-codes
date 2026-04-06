#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,ma,mb; cin>>n>>ma>>mb;
	vector<int> a(n),b(n),c(n); rep(i,n) cin>>a[i]>>b[i]>>c[i];

	int dp[401][401];
	rep(y,401) rep(x,401) dp[y][x]=INF;
	dp[0][0]=0;
	rep(i,n){
		for(int y=400;y>=b[i];y--) for(int x=400;x>=a[i];x--) {
			dp[y][x]=min(dp[y][x],dp[y-b[i]][x-a[i]]+c[i]);
		}
	}

	int ans=INF;
	rep(y,401) rep(x,401) if(y>0 && x>0 && y*ma==x*mb) ans=min(ans,dp[y][x]);
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
