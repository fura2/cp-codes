#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k;
	string s; cin>>k>>s;
	if(s.length()<=k) cout<<s<<'\n';
	else cout<<s.substr(0,k)+"..."<<'\n';
	return 0;
}
