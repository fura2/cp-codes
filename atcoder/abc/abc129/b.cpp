#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,w[100]; cin>>n;
	rep(i,n) cin>>w[i];

	int ans=10000;
	rep(t,n-1) ans=min(ans,abs(accumulate(w,w+t+1,0)-accumulate(w+t+1,w+n,0)));
	cout<<ans<<endl;

	return 0;
}
