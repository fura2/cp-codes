#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,k; cin>>n>>k;
	lint ans=0;
	for(int b=k+1;b<=n;b++){
		ans+=(b-k)*(n/b)+max(n%b-k+1,0LL);
	}
	if(k==0) ans-=n;
	cout<<ans<<endl;

	return 0;
}
