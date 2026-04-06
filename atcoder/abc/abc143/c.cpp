#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int ans=0;
	rep(i,n) if(i==n-1 || s[i]!=s[i+1]) ans++;
	cout<<ans<<endl;

	return 0;
}
