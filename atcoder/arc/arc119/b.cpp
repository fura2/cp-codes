#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s,t; cin>>n>>s>>t;

	vector<int> from,to;
	rep(i,n){
		if(s[i]=='0') from.emplace_back(i);
		if(t[i]=='0') to.emplace_back(i);
	}
	if(from.size()!=to.size()){
		puts("-1");
		return 0;
	}

	int ans=from.size();
	rep(i,from.size()) if(from[i]==to[i]) ans--;
	printf("%d\n",ans);

	return 0;
}
