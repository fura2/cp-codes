#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;

	lint ans=0;
	for(lint x=1;x<=1000000;x++){
		if(stoll(to_string(x)+to_string(x))<=n) ans++;
	}
	cout<<ans<<'\n';

	return 0;
}
