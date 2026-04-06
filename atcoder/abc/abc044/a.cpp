#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k,x,y; cin>>n>>k>>x>>y;

	int ans=0;
	rep(i,n) ans+=(i<k?x:y);
	cout<<ans<<'\n';

	return 0;
}
