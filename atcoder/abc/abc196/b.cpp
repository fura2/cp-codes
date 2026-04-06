#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int x=s.find('.');
	if(x!=string::npos) s=s.substr(0,x);
	cout<<s<<'\n';

	return 0;
}
