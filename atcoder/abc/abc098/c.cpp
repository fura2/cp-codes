#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int w=0,e=0;
	rep(i,n) if(s[i]=='E') e++;

	int ans=n;
	rep(i,n){
		if(s[i]=='E') e--;
		ans=min(ans,w+e);
		if(s[i]=='W') w++;
	}
	cout<<ans<<endl;

	return 0;
}
