#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	rep(i,s.length()) cout<<(char)(i==0?toupper(s[i]):tolower(s[i]));
	cout<<'\n';
	return 0;
}
