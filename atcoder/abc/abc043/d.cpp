#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int n=s.length();
	rep(i,n-1) if(s[i]==s[i+1]) return printf("%d %d\n",i+1,i+2),0;
	rep(i,n-2) if(s[i]==s[i+2]) return printf("%d %d\n",i+1,i+3),0;
	puts("-1 -1");

	return 0;
}
