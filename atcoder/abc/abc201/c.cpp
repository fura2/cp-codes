#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int ans=0;
	rep(x,10000){
		bool b[10]={};
		int y=x;
		rep(i,4){
			b[y%10]=true;
			y/=10;
		}
		bool ok=true;
		rep(i,10){
			if(s[i]=='o' && !b[i]) ok=false;
			if(s[i]=='x' &&  b[i]) ok=false;
		}
		if(ok) ans++;
	}
	cout<<ans<<'\n';

	return 0;
}
