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
	int n,k,r,s,p;
	string t; cin>>n>>k>>r>>s>>p>>t;

	int ans=0;
	rep(i,k){
		string h;
		for(int j=i;j<n;j+=k) h+=t[j];

		for(auto q:run_length_encoding(h)){
			if     (q.first=='r') ans+=(q.second+1)/2*p;
			else if(q.first=='s') ans+=(q.second+1)/2*r;
			else                  ans+=(q.second+1)/2*s;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
