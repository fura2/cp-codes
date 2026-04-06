#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	rep(i,s.length()) if(s[i]!=t[i]) {
		if((s[i]!='@' && t[i]!='@')
		|| (s[i]=='@' && !strchr("atcoder",t[i]))
		|| (t[i]=='@' && !strchr("atcoder",s[i]))){
			cout<<"You will lose"<<endl;
			return 0;
		}
	}
	cout<<"You can win"<<endl;

	return 0;
}
