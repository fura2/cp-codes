#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string f(string &s){
	map<char,char> g;
	for(char &c:s){
		if(g.count(c)==0) g[c]='A'+g.size();
		c=g[c];
	}
	return s;
}

int main(){
	string s,t; cin>>s>>t;
	cout<<(f(s)==f(t)?"Yes":"No")<<endl;
	return 0;
}
