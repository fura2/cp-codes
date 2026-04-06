#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
using lint=long long;

using namespace std;

int main(){
	lint n,k; cin>>n>>k;

	auto f=[&](lint sum){
		return sum<=n?sum-1:2*n-sum+1;
	};

	lint ans=0;
	for(int x=2;x<=2*n;x++){
		lint y=x-k;
		if(2<=y && y<=2*n){
			ans+=f(x)*f(y);
		}
	}
	cout<<ans<<'\n';

	return 0;
}
