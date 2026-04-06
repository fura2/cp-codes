#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a[100]; cin>>n;
	rep(i,n) cin>>a[i];

	sort(a,a+n);

	int ans=0;
	rep(i,n) ans+=(i%2==0?1:-1)*a[n-i-1];
	cout<<ans<<endl;

	return 0;
}
