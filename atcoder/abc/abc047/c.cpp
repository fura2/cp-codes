#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int n=s.length(),ans=0;
	rep(i,n-1) if(s[i]!=s[i+1]) ans++;
	cout<<ans<<endl;

	return 0;
}
