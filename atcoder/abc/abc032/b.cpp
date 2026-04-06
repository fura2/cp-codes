#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int k; cin>>s>>k;

	set<string> A;
	rep(i,(int)s.length()-k+1) A.emplace(s.substr(i,k));
	cout<<A.size()<<'\n';

	return 0;
}
