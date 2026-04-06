#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;
	rep(i,s.length()) s[i]='A'+(s[i]-'A'+n)%26;
	cout<<s<<'\n';
	return 0;
}
