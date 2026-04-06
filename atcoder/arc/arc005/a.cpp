#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int ans=0;
	rep(i,n){
		string s; cin>>s;
		if(i==n-1) s=s.substr(0,s.length()-1);
		if(s=="TAKAHASHIKUN" || s=="Takahashikun" || s=="takahashikun") ans++;
	}
	cout<<ans<<endl;

	return 0;
}
