#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;

	int ans=1e9;
	rep(S,1<<n){
		int res=1;
		rep(i,n) res=(S>>i&1?res*2:res+k);
		ans=min(ans,res);
	}
	cout<<ans<<endl;

	return 0;
}
