#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;

	int ans=-1e9;
	rep(i,3){
		rep(d,10) if(i>0 || d>0) {
			int a,b;
			a=stoi(s.substr(0,i)+char('0'+d)+s.substr(i+1));
			b=stoi(t);
			ans=max(ans,a-b);
			a=stoi(s);
			b=stoi(t.substr(0,i)+char('0'+d)+t.substr(i+1));
			ans=max(ans,a-b);
		}
	}
	printf("%d\n",ans);

	return 0;
}
