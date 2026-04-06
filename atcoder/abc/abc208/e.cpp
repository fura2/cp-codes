#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long TEN[19]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000,10000000000000000,100000000000000000,1000000000000000000};

string s;
lint k;

map<lint,lint> memo[20][2][2];

lint dfs(int i,lint prod,bool smaller,bool leading0){
	if(prod>k) prod=k+1;

	if(memo[i][smaller][leading0].count(prod)>0){
		return memo[i][smaller][leading0][prod];
	}
	lint& res=memo[i][smaller][leading0][prod];

	if(i==s.length()){
		return res=(prod<=k?1:0);
	}

	if(!leading0 && prod==0){
		if(!smaller){
			return res=stoll(s.substr(i))+1;
		}
		else{
			return res=TEN[s.length()-i];
		}
	}

	res=0;
	rep(d,10){
		if(!smaller && d>s[i]-'0') break;
		if(d==0){
			res+=dfs(i+1,leading0?prod:0,smaller||d<s[i]-'0',leading0);
		}
		else{
			res+=dfs(i+1,prod*d,smaller||d<s[i]-'0',false);
		}
	}
	return res;
}

int main(){
	cin>>s>>k;
	cout<<dfs(0,1,false,true)-1<<'\n';
	return 0;
}
