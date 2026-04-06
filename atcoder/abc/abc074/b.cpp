#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k,x[100]; cin>>n>>k;
	rep(i,n) cin>>x[i];

	int ans=0;
	rep(i,n) ans+=2*min(x[i],k-x[i]);
	cout<<ans<<endl;

	return 0;
}
