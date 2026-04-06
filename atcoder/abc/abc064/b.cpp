#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int mn=1000,mx=0;
	rep(i,n){
		int a; cin>>a;
		mn=min(mn,a);
		mx=max(mx,a);
	}
	cout<<mx-mn<<endl;

	return 0;
}
