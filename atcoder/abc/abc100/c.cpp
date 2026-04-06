#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;

	int ans=0;
	rep(i,n){
		int a; cin>>a;
		while(a%2==0) ans++, a>>=1;
	}
	cout<<ans<<endl;

	return 0;
}
