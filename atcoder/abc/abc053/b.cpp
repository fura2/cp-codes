#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int i0=-1,i1;
	rep(i,s.length()){
		if(s[i]=='A' && i0==-1) i0=i;
		if(s[i]=='Z') i1=i;
	}
	cout<<i1-i0+1<<'\n';
	return 0;
}
