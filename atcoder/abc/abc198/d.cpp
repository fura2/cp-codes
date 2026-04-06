#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s1,s2,s3; cin>>s1>>s2>>s3;

	int f[128];
	{
		map<char,int> h;
		for(string s:{s1,s2,s3}){
			for(char c:s) if(h.count(c)==0) h[c]=h.size();
		}
		if(h.size()>10){
			cout<<"UNSOLVABLE\n";
			return 0;
		}
		for(auto [c,id]:h) f[c]=id;
	}

	vector<int> p(10);
	iota(p.begin(),p.end(),0);
	do{
		if(p[f[s1[0]]]==0) continue;
		if(p[f[s2[0]]]==0) continue;
		if(p[f[s3[0]]]==0) continue;

		lint x1=0,x2=0,x3=0;
		for(char c:s1) x1=10*x1+p[f[c]];
		for(char c:s2) x2=10*x2+p[f[c]];
		for(char c:s3) x3=10*x3+p[f[c]];
		if(x1+x2==x3){
			cout<<x1<<'\n';
			cout<<x2<<'\n';
			cout<<x3<<'\n';
			return 0;
		}
	}while(next_permutation(p.begin(),p.end()));

	cout<<"UNSOLVABLE\n";

	return 0;
}
