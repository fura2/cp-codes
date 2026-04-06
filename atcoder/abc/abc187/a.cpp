#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	int a=0,b=0;
	rep(i,3){
		a+=s[i]-'0';
		b+=t[i]-'0';
	}
	printf("%d\n",max(a,b));

	return 0;
}
