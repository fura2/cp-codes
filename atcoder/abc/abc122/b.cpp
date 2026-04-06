#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	for(int l=n;;l--) rep(i,n-l+1) {
		if(regex_match(s.substr(i,l),regex("[AGTC]*"))) { cout<<l<<endl; return 0; }
	}
	return 0;
}
