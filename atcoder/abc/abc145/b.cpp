#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;
	cout<<(s.substr(0,n/2)+s.substr(0,n/2)==s?"Yes":"No")<<'\n';
	return 0;
}
