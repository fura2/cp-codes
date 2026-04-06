#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int total=accumulate(a.begin(),a.end(),0);

	vector<bool> dp(total+1);
	dp[0]=true;
	rep(i,n){
		for(int x=total;x>=a[i];x--) if(dp[x-a[i]]) dp[x]=true;
	}

	int ans=total;
	rep(x,total+1) if(dp[x]) ans=min(ans,max(x,total-x));
	printf("%d\n",ans);

	return 0;
}
