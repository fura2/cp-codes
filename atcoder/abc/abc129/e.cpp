#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1000000007;

int three[1000001];

string s;

int dfs(int i,bool b){
	if(i==s.length()) return 1;

	if(b){
		if(s[i]=='1'){
			return (2LL*dfs(i+1,true)%MOD+dfs(i+1,false))%MOD;
		}
		else{
			return dfs(i+1,true);
		}
	}
	else{
		return three[s.length()-i];
	}
}

int main(){
	three[0]=1;
	rep(i,1000000) three[i+1]=three[i]*3LL%MOD;

	cin>>s;
	cout<<dfs(0,true)<<endl;

	return 0;
}
