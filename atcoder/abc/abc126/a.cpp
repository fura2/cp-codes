#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k;
	string s; cin>>n>>k>>s;
	s[k-1]=tolower(s[k-1]);
	cout<<s<<endl;

	return 0;
}
