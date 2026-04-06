#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	string s(n,'?');
	rep(i,m){
		int a;
		char b; scanf("%d %c",&a,&b); a--;
		if(s[a]=='?' || s[a]==b) s[a]=b;
		else return puts("-1"),0;
	}

	if(n>1 && s[0]=='0') return puts("-1"),0;
	rep(i,n) if(s[i]=='?') s[i]=(n>1&&i==0?'1':'0');

	cout<<s<<'\n';

	return 0;
}
