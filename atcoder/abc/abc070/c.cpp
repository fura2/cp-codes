#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint gcd(lint a,lint b){ return b?gcd(b,a%b):a; }
lint lcm(lint a,lint b){ return a/gcd(a,b)*b; }

int main(){
	int n; cin>>n;
	lint ans=1;
	rep(i,n){
		lint t; cin>>t;
		ans=lcm(ans,t);
	}
	cout<<ans<<endl;
	return 0;
}
