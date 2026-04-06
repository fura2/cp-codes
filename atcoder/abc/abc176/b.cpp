#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int ans=0;
	for(char c:s) ans=(ans+c-'0')%9;
	cout<<(ans==0?"Yes":"No")<<'\n';
	return 0;
}
