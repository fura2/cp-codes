#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	set<string> S;
	rep(i,n){
		string s; cin>>s;
		S.emplace(s);
	}
	cout<<S.size()<<'\n';
	return 0;
}
