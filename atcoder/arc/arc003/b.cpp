#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	string s[100];
	rep(i,n) cin>>s[i];

	rep(i,n) reverse(s[i].begin(),s[i].end());
	sort(s,s+n);
	rep(i,n) reverse(s[i].begin(),s[i].end());

	rep(i,n) cout<<s[i]<<'\n';

	return 0;
}
