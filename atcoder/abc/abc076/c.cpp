#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	int n=s.length(),m=t.length();

	if(n<m){ cout<<"UNRESTORABLE"<<endl; return 0; }

	string ans="~";
	rep(i,n-m+1){
		bool ok=true;
		string r=s;
		rep(j,m){
			if(s[i+j]=='?'){
				r[i+j]=t[j];
			}
			else if(s[i+j]!=t[j]){
				ok=false;
			}
		}
		if(!ok) continue;

		rep(j,n) if(r[j]=='?') r[j]='a';
		ans=min(ans,r);
	}
	cout<<(ans=="~"?"UNRESTORABLE":ans)<<endl;

	return 0;
}
