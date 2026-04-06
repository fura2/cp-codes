#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int k; cin>>s>>k;

	int n=s.length();
	vector<string> S;
	rep(l,5) rep(i,n-l) S.emplace_back(s.substr(i,l+1));

	sort(S.begin(),S.end());
	S.erase(unique(S.begin(),S.end()),S.end());

	cout<<S[k-1]<<endl;

	return 0;
}
