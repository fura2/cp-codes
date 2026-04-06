#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	string res;
	for(char c:s){
		if(c!='B') res+=c;
		else if(!res.empty()) res.pop_back(); 
	}
	cout<<res<<'\n';

	return 0;
}
