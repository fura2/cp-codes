#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,h[20]; cin>>n;
	rep(i,n) cin>>h[i];

	int ans=0;
	rep(i,n){
		bool ok=true;
		rep(j,i) if(h[j]>h[i]) ok=false;
		if(ok) ans++;
	}
	cout<<ans<<endl;

	return 0;
}
