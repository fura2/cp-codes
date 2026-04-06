#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	char f[128];
	f['0']='0';
	f['1']='1';
	f['6']='9';
	f['8']='8';
	f['9']='6';

	string s; cin>>s;
	for(char& c:s) c=f[c];
	reverse(s.begin(),s.end());
	cout<<s<<'\n';

	return 0;
}
