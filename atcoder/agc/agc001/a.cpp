#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,l[200]; cin>>n;
	rep(i,2*n) cin>>l[i];

	sort(l,l+2*n);

	int ans=0;
	rep(i,n) ans+=l[2*i];
	cout<<ans<<endl;

	return 0;
}
