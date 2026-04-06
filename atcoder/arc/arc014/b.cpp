#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	set<string> D;
	string pre;
	rep(i,n){
		string s; cin>>s;
		if(D.count(s)==1 || (i>0 && pre.back()!=s[0])) return cout<<(i%2==0?"LOSE":"WIN")<<'\n',0;
		D.emplace(s);
		pre=s;
	}
	cout<<"DRAW\n";

	return 0;
}
