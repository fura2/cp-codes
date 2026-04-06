#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,x; cin>>a>>b>>x;

	lint ans;
	if(a>0) ans=b/x-(a-1)/x;
	else    ans=b/x+1;
	cout<<ans<<'\n';

	return 0;
}
