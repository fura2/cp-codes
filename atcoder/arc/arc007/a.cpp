#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	char x;
	string s,t; cin>>x>>s;
	for(char& c:s) if(c!=x) t+=c;
	cout<<t<<'\n';
	return 0;
}
