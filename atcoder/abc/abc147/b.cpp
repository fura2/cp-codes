#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	int ans=0;
	rep(i,n/2) if(s[i]!=s[n-i-1]) ans++;
	cout<<ans;
	return 0;
}
