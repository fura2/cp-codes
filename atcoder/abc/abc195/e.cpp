#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
string s,x;

int memo[200001][7];

int dfs(int i,int mod){
	int& res=memo[i][mod];
	if(res!=-1) return res;

	if(i==n) return res=(mod==0?1:0);

	int d=s[i]-'0';
	if(x[i]=='T'){
		if(dfs(i+1,(10*mod+d)%7) || dfs(i+1,10*mod%7)) res=1;
		else res=0;
	}
	else{
		if(!dfs(i+1,(10*mod+d)%7) || !dfs(i+1,10*mod%7)) res=0;
		else res=1;
	}
	return res;
}

int main(){
	cin>>n>>s>>x;

	memset(memo,-1,sizeof memo);
	puts(dfs(0,0)?"Takahashi":"Aoki");

	return 0;
}
