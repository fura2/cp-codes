#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	int n=s.length();
	rep(i,n) if(s.substr(i)+s.substr(0,i)==t) { cout<<"Yes"<<endl; return 0; }
	cout<<"No"<<endl;

	return 0;
}
