#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m,combo,all; scanf("%d%d%d%d",&n,&m,&combo,&all);
	int score[128],id[128];
	rep(i,m){
		char c;
		int p; scanf(" %c%d",&c,&p);
		score[c]=p;
		id[c]=i;
	}
	string s; cin>>s;

	int dp[2][1<<10][11];
	rep(t,2) rep(S,1<<m) rep(last,m+1) dp[t][S][last]=-INF;
	int cur=0,next=1;
	dp[cur][0][m]=0;
	for(char c:s){
		rep(S,1<<m) rep(last,m+1) if(dp[cur][S][last]!=-INF) {
			// don't use
			dp[next][S][last]=max(dp[next][S][last],dp[cur][S][last]);
			// use
			int S2=S|(1<<id[c]);
			int bonus=0;
			if(last==id[c]) bonus+=combo;
			if(S!=(1<<m)-1 && S2==(1<<m)-1) bonus+=all;
			dp[next][S2][id[c]]=max(dp[next][S2][id[c]],dp[cur][S][last]+score[c]+bonus);
		}
		swap(cur,next);
	}

	int ans=-INF;
	rep(S,1<<m) rep(last,m+1) ans=max(ans,dp[cur][S][last]);
	printf("%d\n",ans);

	return 0;
}
