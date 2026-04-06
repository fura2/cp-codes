#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool ispali(string s){
	string t=s;
	reverse(t.begin(),t.end());
	return s==t;
}

int main(){
	string s; cin>>s;
	int n=s.length();
	puts(ispali(s)&&ispali(s.substr(0,n/2))?"Yes":"No");
	return 0;
}
