#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	int ans=0;
	rep(i,s.length()) if(s[i]!=t[i]) ans++;
	cout<<ans<<'\n';
	return 0;
}
