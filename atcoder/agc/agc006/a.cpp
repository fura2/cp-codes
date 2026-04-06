#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s,t; cin>>n>>s>>t;
	rep(i,n+1) if(s.substr(i)==t.substr(0,n-i)) {
		printf("%d\n",n+i);
		break;
	}
	return 0;
}
