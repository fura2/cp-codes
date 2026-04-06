#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint modpow(lint a,lint k,int m){
	lint r=1%m;
	for(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;
	return r;
}

int n;
string s;

char memo[101][101];

char dfs(int k,int l){
	if(memo[k][l]!=0) return memo[k][l];

	char& res=memo[k][l];
	if(k==0) return res=s[l];

	char c1=dfs(k-1,l);
	char c2=dfs(k-1,(l+modpow(2,k-1,n))%n);

	if(c1==c2) return res=c1;
	if(c1=='R' && c2=='S') return res=c1;
	if(c1=='S' && c2=='P') return res=c1;
	if(c1=='P' && c2=='R') return res=c1;
	return res=c2;
}

int main(){
	int k; cin>>n>>k>>s;
	cout<<dfs(k,0)<<'\n';
	return 0;
}
