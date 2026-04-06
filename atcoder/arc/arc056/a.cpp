#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,k,l; cin>>a>>b>>k>>l;

	lint ans=k/l*b;
	k%=l;
	ans+=min(k*a,b);
	cout<<ans<<'\n';

	return 0;
}
