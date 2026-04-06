#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string s;

int memo[10];

int dfs(int i,bool smaller){
	if(i==s.length()) return 0;

	if(smaller && memo[i]!=-1) return memo[i];

	int res=0;
	if(smaller){
		rep(d,10){
			res+=dfs(i+1,true);
			if(d==1) res+=pow(10,s.length()-i-1);
		}
	}
	else{
		rep(d,s[i]-'0'+1){
			bool smaller2=(d<s[i]-'0');
			res+=dfs(i+1,smaller2);
			if(d==1){
				if(smaller2){
					res+=pow(10,s.length()-i-1);
				}
				else{
					res+=(i==s.length()-1?0:stoi(s.substr(i+1)))+1;
				}
			}
		}
	}
	return memo[i]=res;
}

int main(){
	memset(memo,-1,sizeof memo);

	cin>>s;
	cout<<dfs(0,false)<<'\n';

	return 0;
}
