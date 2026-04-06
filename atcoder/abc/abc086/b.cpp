#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	rep(i,1000) if(i*i==stoi(s+t)) { cout<<"Yes"<<endl; return 0; }
	cout<<"No"<<endl;
	return 0;
}
