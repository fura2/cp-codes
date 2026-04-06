#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	string s[100];
	rep(i,n) cin>>s[i];

	bool ok=true;
	rep(i,n) rep(j,i) if(s[i]==s[j]) ok=false;
	rep(i,n-1) if(s[i].back()!=s[i+1].front()) ok=false;
	cout<<(ok?"Yes":"No")<<endl;

	return 0;
}
