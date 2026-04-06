#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int n; cin>>s>>n; n--;
	cout<<s[n/5]<<s[n%5]<<'\n';
	return 0;
}
