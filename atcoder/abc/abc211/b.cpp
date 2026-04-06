#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	set<string> S;
	rep(_,4){
		string s; cin>>s;
		S.emplace(s);
	}
	cout<<(S.size()==4?"Yes":"No")<<'\n';
	return 0;
}
