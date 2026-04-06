#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;

	set<string> S;
	rep(i,n){
		string s; cin>>s;
		if(s[0]=='!'){
			string t=s.substr(1);
			if(S.count(t)>0){
				cout<<t<<'\n';
				return 0;
			}
		}
		else{
			string t="!"+s;
			if(S.count(t)>0){
				cout<<s<<'\n';
				return 0;
			}
		}
		S.emplace(s);
	}
	puts("satisfiable");

	return 0;
}
