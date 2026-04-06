#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	cout<<((s.length()%2==0)==(s.front()==s.back())?"First":"Second")<<'\n';
	return 0;
}
