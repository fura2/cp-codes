#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int calc(string s,int c){
	int n=s.length();
	if(count(s.begin(),s.end(),c)==n) return 0;

	string t;
	rep(i,n-1) t+=(s[i]==c?s[i]:s[i+1]);
	return calc(t,c)+1;
}

int main(){
	string s; cin>>s;

	int ans=100;
	for(char c='a';c<='z';c++) ans=min(ans,calc(s,c));
	cout<<ans<<'\n';

	return 0;
}
