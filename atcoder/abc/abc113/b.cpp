#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,t,a; cin>>n>>t>>a;
	int h[1000];
	rep(i,n) cin>>h[i];

	int ans=0;
	rep(i,n) if(abs(t-0.006*h[i]-a)<abs(t-0.006*h[ans]-a)) ans=i;
	cout<<ans+1<<endl;

	return 0;
}
