#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<pair<char,int>> run_length_encoding(const string& s){
	vector<pair<char,int>> res;
	int n=s.length(),pre=0;
	rep(i,n) if(i==n-1 || s[i]!=s[i+1]) res.emplace_back(s[i],i-pre+1), pre=i+1;
	return res;
}

int main(){
	int n; cin>>n;
	string B[100];
	rep(i,n) cin>>B[i];

	int ans=0;
	rep(j,9){
		string s;
		rep(i,n) s+=B[i][j];
		for(auto p:run_length_encoding(s)){
			if(p.first=='x') ans+=p.second;
			if(p.first=='o') ans++;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
