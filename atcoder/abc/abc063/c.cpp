#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	bool dp[10001]={true};
	rep(i,n){
		int a; cin>>a;
		for(int w=10000;w>=a;w--) dp[w]|=dp[w-a];
	}

	int ans=0;
	rep(w,10001) if(dp[w] && w%10!=0) ans=max(ans,w);
	cout<<ans<<endl;

	return 0;
}
