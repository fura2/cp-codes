#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,pttn;

bool dfs(int S,int dep){
	if(dep==0) return S==(1<<n)-1;
	rep(i,n){
		int pttn2=(pttn>>i)|((pttn&((1<<i)-1))<<(n-i));
		if((S|pttn2)!=S && dfs(S|pttn2,dep-1)) return true;
	}
	return false;
}

int main(){
	string s; cin>>s;
	n=s.length();
	rep(i,n) if(s[i]=='o') pttn|=1<<i;

	int dep;
	for(dep=1;!dfs(0,dep);dep++);
	cout<<dep<<'\n';

	return 0;
}
