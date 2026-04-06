#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	string B[300];
	rep(i,n) cin>>B[i];

	int ans=0;
	rep(b,n){
		bool ok=true;
		rep(i,n) rep(j,n) if(B[i][(j+b)%n]!=B[j][(i+b)%n]) ok=false;
		if(ok) ans+=n;
	}
	cout<<ans<<'\n';

	return 0;
}
