#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	map<string,int> D;
	rep(i,n){
		string s; cin>>s;
		++D[s];
	}

	int mx=0;
	for(auto p:D) mx=max(mx,p.second);

	for(auto p:D) if(p.second==mx) cout<<p.first<<'\n';

	return 0;
}
