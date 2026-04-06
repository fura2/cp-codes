#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;

	if(n%2==1) return puts("0"),0;

	lint ans=0,f=5;
	while(n>=f) ans+=n/(2*f), f*=5;
	cout<<ans<<'\n';

	return 0;
}
