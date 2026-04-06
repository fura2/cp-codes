#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,W; cin>>n>>W;
	vector<int> a(n),b(n);
	rep(i,n) cin>>a[i]>>b[i];

	{
		vector<pair<int,int>> p(n);
		rep(i,n) p[i]={a[i],b[i]};
		sort(p.rbegin(),p.rend());
		rep(i,n) tie(a[i],b[i])=p[i];
	}

	int ans=0;
	vector<int> dp(W+1);
	rep(i,n){
		ans=max(ans,dp[W]+b[i]);
		for(int w=W;w>=a[i];w--) dp[w]=max(dp[w],dp[w-a[i]]+b[i]);
		rep(w,W) dp[w+1]=max(dp[w+1],dp[w]);
	}
	cout<<ans<<endl;

	return 0;
}
