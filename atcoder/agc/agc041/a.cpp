#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,a,b; cin>>n>>a>>b;

	if((b-a)%2==0) cout<<(b-a)/2<<'\n';
	else           cout<<min(a+(b-a-1)/2,(n-b+1)+(b-a-1)/2)<<'\n';

	return 0;
}
