#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	rep(i,n) if(s[i]!=s[n-i-1] && s[i]!='*' && s[n-1-i]!='*') {
		puts("NO");
		return 0;
	}
	puts("YES");

	return 0;
}
