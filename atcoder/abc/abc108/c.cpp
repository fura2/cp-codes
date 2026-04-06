#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; cin>>n>>k;
	lint ans=0;
	for(int a=1;a<=min(n,k);a++) if(2*a%k==0) {
		lint x=(n-a+k)/k;
		ans+=x*x*x;
	}
	cout<<ans<<endl;

	return 0;
}
