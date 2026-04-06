#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	if(s.length()+1==t.length()){
		t.pop_back();
		puts(s==t?"Yes":"No");
	}
	else{
		puts("No");
	}
	return 0;
}
