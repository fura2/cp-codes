#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	map<string,int> f;
	int n; cin>>n;
	rep(i,n){
		string s; cin>>s;
		++f[s];
	}

	string ans;
	int mx=-1;
	for(auto p:f) if(p.second>mx) mx=p.second, ans=p.first;
	cout<<ans<<'\n';

	return 0;
}
