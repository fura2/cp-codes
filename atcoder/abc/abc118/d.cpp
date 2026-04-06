#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int f[]={6,2,5,5,4,5,6,3,7,6};

	int n,m; cin>>n>>m;
	vector<int> a(m);
	rep(i,m) cin>>a[i];
	sort(a.begin(),a.end());

	pair<int,int> dp[10001];
	int pre[10001];
	rep(i,n) dp[i+1]={-1,0};
	for(int d:a){
		int cost=f[d];
		rep(i,n-cost+1) if(~dp[i].first) {
			pair<int,int> next={dp[i].first+1,d};
			if(dp[i+cost]<next){
				dp[i+cost]=next;
				pre[i+cost]=i;
			}
		}
	}

	int i=n;
	do{
		putchar('0'+dp[i].second);
		i=pre[i];
	}while(i>0);

	return 0;
}
