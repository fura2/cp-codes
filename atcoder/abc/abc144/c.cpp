#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;

	lint ans=n;
	for(lint d=1;d*d<=n;d++) if(n%d==0) {
		ans=min(ans,d+n/d-2);
	}
	cout<<ans<<endl;

	return 0;
}
