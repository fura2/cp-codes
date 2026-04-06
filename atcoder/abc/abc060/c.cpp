#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,T; cin>>n>>T;

	int ans=0,now=0;
	rep(i,n){
		int t; cin>>t;
		if(now+T<t) ans+=T;
		else        ans+=t-now;
		now=t;
	}
	ans+=T;
	cout<<ans<<endl;

	return 0;
}
