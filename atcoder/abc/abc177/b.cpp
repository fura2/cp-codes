#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	int m=s.length(),n=t.length();

	int ans=n;
	rep(i,m-n+1){
		int cnt=0;
		rep(j,n) if(s[i+j]!=t[j]) cnt++;
		ans=min(ans,cnt);
	}
	cout<<ans<<'\n';

	return 0;
}
