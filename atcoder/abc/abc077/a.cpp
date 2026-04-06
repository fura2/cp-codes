#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s[2];
	cin>>s[0]>>s[1];
	cout<<(s[0][0]==s[1][2]&&s[0][1]==s[1][1]&&s[0][2]==s[1][0]?"YES":"NO")<<'\n';
	return 0;
}
