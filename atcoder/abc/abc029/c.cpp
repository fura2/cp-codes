#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void dfs(int n,string s){
	if(n==0) cout<<s<<'\n';
	else{
		rep(i,3) dfs(n-1,s+(char)('a'+i));
	}
}

int main(){
	int n; cin>>n;
	dfs(n,"");
	return 0;
}
