#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool solve(vector<int> X,int tar,bool first){
	bool dp[2][20000]={};
	int from=0,to=1;
	dp[from][10000]=true;
	for(int a:X){
		rep(i,20000) if(0<=i+a && i+a<20000 && dp[from][i]) dp[to][i+a]=true;
		if(!first){
			rep(i,20000) if(0<=i-a && i-a<20000 && dp[from][i]) dp[to][i-a]=true;
		}
		first=false;
		fill(dp[from],dp[from]+20000,false);
		swap(from,to);
	}
	return dp[from][tar+10000];
}

int main(){
	string s;
	int tx,ty;
	cin>>s>>tx>>ty;
	s+='T';
	int n=s.length();

	int pre=0;
	bool par=true;
	vector<int> X,Y;
	rep(i,n) if(s[i]=='T') {
		if(par) X.emplace_back(i-pre);
		else    Y.emplace_back(i-pre);
		pre=i+1;
		par=!par;
	}

	cout<<(solve(X,tx,s[0]=='F')&&solve(Y,ty,false)?"Yes":"No")<<endl;

	return 0;
}
