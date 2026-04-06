#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;
	int ans=0;
	rep(i,n){
		int a; cin>>a;
		if(a>=k) ans++;
	}
	cout<<ans<<endl;

	return 0;
}
