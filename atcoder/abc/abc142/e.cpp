#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; cin>>n>>m;
	int a[1000],c[1000]={};
	rep(i,m){
		int b; cin>>a[i]>>b;
		rep(j,b){
			int t; cin>>t;
			c[i]|=1<<(t-1);
		}
	}

	int dp[1<<12];
	rep(S,1<<n) dp[S]=INF;
	dp[0]=0;
	rep(i,m){
		for(int S=(1<<n)-1;S>=0;S--){
			dp[S|c[i]]=min(dp[S|c[i]],dp[S]+a[i]);
		}
	}
	if(dp[(1<<n)-1]<INF) cout<<dp[(1<<n)-1]<<endl; else cout<<-1<<endl;

	return 0;
}
