#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	bool ok=false;
	rep(i,3) if((s[i]-'0'+1)%10!=(s[i+1]-'0')) ok=true;
	if(set(s.begin(),s.end()).size()==1){
		ok=false;
	}
	puts(ok?"Strong":"Weak");

	return 0;
}
