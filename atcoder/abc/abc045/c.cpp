#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint dfs(string s,lint sum){
	int n=s.length();
	if(n==0) return sum;
	lint res=0;
	rep(i,n) res+=dfs(s.substr(i+1),sum+stoll(s.substr(0,i+1)));
	return res;
}

int main(){
	string s; cin>>s;
	cout<<dfs(s,0)<<'\n';
	return 0;
}
