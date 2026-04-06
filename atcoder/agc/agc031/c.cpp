#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<string> dfs(string s,string t){
	int n=s.length();

	if(n==1) return {s,t};

	int p;
	for(p=0;p<n;p++) if(s[p]!=t[p]) break;

	string s2,t2,r;
	s2=s.substr(0,p)+s.substr(p+1);
	t2=t.substr(0,p)+t.substr(p+1);
	r=s2;
	r[0]=(r[0]=='0'?'1':'0');

	vector<string> res;
	for(auto x:dfs(s2,r)) res.emplace_back(x.substr(0,p)+s[p]+x.substr(p));
	for(auto x:dfs(r,t2)) res.emplace_back(x.substr(0,p)+t[p]+x.substr(p));
	return res;
}

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b);

	string s(n,'0'),t(n,'0');
	rep(i,n){
		if(a>>i&1) s[n-i-1]='1';
		if(b>>i&1) t[n-i-1]='1';
	}

	if((count(s.begin(),s.end(),'1')+count(t.begin(),t.end(),'1'))%2==0){
		puts("NO");
	}
	else{
		puts("YES");
		for(auto r:dfs(s,t)){
			printf("%d ",stoi(r,nullptr,2));
		}
		puts("");
	}

	return 0;
}
