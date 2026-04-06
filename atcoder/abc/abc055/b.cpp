#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; cin>>n;
	lint ans=1;
	rep(i,n) ans=ans*(i+1)%1000000007;
	cout<<ans<<'\n';

	return 0;
}
