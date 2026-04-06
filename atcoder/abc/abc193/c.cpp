#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;

	set<lint> S;
	for(lint a=2;a*a<=n;a++){
		for(lint x=a*a;x<=n;x*=a) S.emplace(x);
	}
	cout<<n-S.size()<<'\n';

	return 0;
}
