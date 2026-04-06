#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int ans=0;
	rep(i,12){
		string s; cin>>s;
		if(count(s.begin(),s.end(),'r')>0) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
