#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d,x; cin>>n>>d>>x;
	int ans=x;
	rep(i,n){
		int a; cin>>a;
		ans+=(d-1)/a+1;
	}
	cout<<ans<<endl;

	return 0;
}
