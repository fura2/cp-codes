#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	string t=s;
	reverse(t.begin(),t.end());
	cout<<(s==t?"YES":"NO")<<'\n';
	return 0;
}
