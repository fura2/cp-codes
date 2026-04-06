#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int i;
	for(i=0;i<s.length();i++){
		if(i+1<s.length() && s[i]=='c' && s[i+1]=='h') i++;
		else if(s[i]=='o');
		else if(s[i]=='k');
		else if(s[i]=='u');
		else return puts("NO"),0;
	}
	puts("YES");
	return 0;
}
