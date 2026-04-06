#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1000000007;

int main(){
	int fib[100002];
	fib[0]=0;
	fib[1]=1;
	rep(i,100000) fib[i+2]=(fib[i+1]+fib[i])%MOD;

	int n,m; cin>>n>>m;
	int ans=1,pre=-1;
	rep(i,m+1){
		int a;
		if(i<m) cin>>a;
		else    a=n+1;
		ans=1LL*ans*fib[a-pre-1]%MOD;
		pre=a;
	}
	cout<<ans<<endl;

	return 0;
}
