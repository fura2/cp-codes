#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k;
	string s; cin>>n>>k>>s;

	k=min(k,15);

	rep(i,k-1){
		s=s+s;
		reverse(s.begin()+n,s.end());

		string t="~";
		rep(j,n+1){
			string tmp=s.substr(j,n);
			reverse(tmp.begin(),tmp.end());
			t=min(t,tmp);
		}
		reverse(t.begin(),t.end());
		s=t;
	}

	string ans="~";
	s=s+s;
	reverse(s.begin()+n,s.end());
	rep(j,n+1) ans=min(ans,s.substr(j,n));
	cout<<ans<<'\n';

	return 0;
}
