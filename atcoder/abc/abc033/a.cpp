#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	cout<<(set<char>(s.begin(),s.end()).size()==1?"SAME":"DIFFERENT")<<'\n';
	return 0;
}
