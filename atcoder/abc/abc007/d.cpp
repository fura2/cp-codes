#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint memo[20][2][2];

string s;
lint dfs(int i,bool smaller,bool ban){
	if(i==s.length()) return ban?1:0;

	if(memo[i][smaller][ban]!=-1) return memo[i][smaller][ban];

	lint res=0;
	if(smaller){
		rep(d,10){
			res+=dfs(i+1,true,ban||d==4||d==9);
		}
	}
	else{
		rep(d,10) if(d<=s[i]-'0') {
			res+=dfs(i+1,d<s[i]-'0',ban||d==4||d==9);
		}
	}
	return memo[i][smaller][ban]=res;
}

int main(){
	lint a,b; cin>>a>>b;

	memset(memo,-1,sizeof memo);
	s=to_string(b);
	lint res1=dfs(0,false,false);

	memset(memo,-1,sizeof memo);
	s=to_string(a-1);
	lint res2=dfs(0,false,false);

	cout<<res1-res2<<'\n';
	return 0;
}
