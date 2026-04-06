#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int hist[26];
	rep(c,26) hist[c]=100;
	rep(i,n){
		string s; cin>>s;
		int tmp[26]={};
		for(char c:s) tmp[c-'a']++;
		rep(c,26) hist[c]=min(hist[c],tmp[c]);
	}

	rep(c,26) cout<<string(hist[c],'a'+c);
	cout<<'\n';

	return 0;
}
