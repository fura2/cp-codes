#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	int ans=999;
	rep(i,n-2) ans=min(ans,abs(stoi(s.substr(i,3))-753));
	cout<<ans<<endl;

	return 0;
}
