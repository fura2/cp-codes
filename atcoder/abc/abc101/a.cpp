#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int ans=0;
	rep(i,4) ans+=(s[i]=='+'?1:-1);
	cout<<ans<<endl;

	return 0;
}
