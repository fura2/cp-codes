#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	cout<<s[0]<<n-2<<s[n-1]<<endl;
	return 0;
}
