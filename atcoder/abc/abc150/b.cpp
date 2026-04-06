#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int ans=0;
	rep(i,n-2) if(s.substr(i,3)=="ABC") ans++;
	cout<<ans<<'\n';

	return 0;
}
