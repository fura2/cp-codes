#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
using lint=long long;

using namespace std;

int main(){
	lint a,b,x; cin>>a>>b>>x;

	lint ans=0;
	rep(i,10){
		if(x-b*(i+1)>=0) ans=max(ans,min((x-b*(i+1))/a,(lint)pow(10,i+1)-1));
	}
	ans=min(ans,(lint)pow(10,9));
	cout<<ans<<'\n';

	return 0;
}
