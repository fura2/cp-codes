#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string solve(string s){
	int n=s.length();
	string t=s;
	sort(t.begin(),t.end());
	if(count(s.begin(),s.end(),'A')<n && s==t) return "B";
	return "A";
}

int main(){
	int t; cin>>t;
	while(t--){
		int n;
		string s; cin>>n>>s;
		cout<<solve(s)<<'\n';
	}
	return 0;
}
