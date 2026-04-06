#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	for(char& c:s){
		if(c=='O') c='0';
		if(c=='D') c='0';
		if(c=='I') c='1';
		if(c=='Z') c='2';
		if(c=='S') c='5';
		if(c=='B') c='8';
	}
	cout<<s<<'\n';
	return 0;
}
