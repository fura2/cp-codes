#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int ans=0,pre=0;
	bool zero=false;
	rep(i,n+1){
		if(i==n || s[i]=='+'){
			if(!zero) ans++;
			zero=false;
			pre=i+1;
		}
		else if(s[i]=='0'){
			zero=true;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
