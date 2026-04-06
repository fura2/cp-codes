#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k,r[100]; cin>>n>>k;
	rep(i,n) cin>>r[i];

	sort(r,r+n);

	double ans=0;
	rep(i,k) ans=(ans+r[n-k+i])/2;
	cout<<setprecision(7)<<ans<<endl;

	return 0;
}
