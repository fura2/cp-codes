#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t,u;
	int a,b; cin>>s>>t>>a>>b>>u;
	if(u==s) a--;
	if(u==t) b--;
	cout<<a<<' '<<b<<'\n';
	return 0;
}
