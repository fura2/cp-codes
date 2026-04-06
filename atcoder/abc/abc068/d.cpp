#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;
using lint=long long;

int main(){
	lint k; cin>>k;

	int n=50;
	lint a[50];
	rep(i,n) a[i]=n-1+k/n;

	k%=n;

	rep(i,k) rep(j,n) {
		if(j==i) a[j]+=n;
		else     a[j]--;
	}

	cout<<n<<endl;
	rep(i,n) cout<<a[i]<<' ';

	return 0;
}
