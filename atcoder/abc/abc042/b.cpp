#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,l; cin>>n>>l;
	string s[100];
	rep(i,n) cin>>s[i];

	sort(s,s+n);

	cout<<accumulate(s,s+n,""s)<<'\n';

	return 0;
}
