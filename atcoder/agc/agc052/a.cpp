#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int n; cin>>n;
	string s[3];
	rep(i,3) cin>>s[i];
	cout<<string(n,'0')+string(n,'1')+"0\n";
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
