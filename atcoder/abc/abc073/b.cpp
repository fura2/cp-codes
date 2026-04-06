#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,ans=0; cin>>n;
	rep(i,n){
		int l,r; cin>>l>>r;
		ans+=r-l+1;
	}
	cout<<ans<<endl;
	return 0;
}
