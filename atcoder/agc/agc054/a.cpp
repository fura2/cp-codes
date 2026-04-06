#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	if(s[0]!=s[n-1]){
		puts("1");
		return 0;
	}

	bool ok=false;
	rep(i,n-1) if(s[i]!=s[0] && s[i+1]!=s[0]) ok=true;
	puts(ok?"2":"-1");

	return 0;
}
