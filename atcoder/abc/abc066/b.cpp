#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length()/2;
	for(int i=1;;i++) if(s.substr(0,n-i)==s.substr(n-i,n-i)) { cout<<2*(n-i)<<endl; break; }
	return 0;
}
