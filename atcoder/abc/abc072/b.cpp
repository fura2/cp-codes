#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	for(int i=0;i<n;i+=2) cout<<s[i];
	cout<<endl;
	return 0;
}
