#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,m; cin>>n>>m;

	lint ans=0;
	ans+=min(n,m/2);
	m-=2*min(n,m/2);
	ans+=m/4;
	cout<<ans<<'\n';

	return 0;
}
