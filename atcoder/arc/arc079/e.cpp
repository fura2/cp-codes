#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; cin>>n;
	lint a[50];
	rep(i,n) cin>>a[i];

	lint ans=0;
	while(1){
		bool end=true;
		rep(i,n) if(a[i]>=n) {
			ans+=a[i]/n;
			rep(j,n) if(j!=i) a[j]+=a[i]/n;
			a[i]%=n;
			end=false;
		}
		if(end) break;
	}
	cout<<ans<<endl;

	return 0;
}
