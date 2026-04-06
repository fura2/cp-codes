#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s;
	lint k; cin>>s>>k;

	int n=s.length(),pos;
	rep(i,n) if(s[i]!='1') { pos=i; break; }
	cout<<(k<=pos?'1':s[pos])<<endl;

	return 0;
}
