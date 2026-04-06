#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<pair<char,int>> run_length_encoding(const string& s){
	vector<pair<char,int>> res;
	int n=s.length(),pre=0;
	rep(i,n) if(i==n-1 || s[i]!=s[i+1]) res.emplace_back(s[i],i-pre+1), pre=i+1;
	return res;
}

int main(){
	string s; cin>>s;

	auto R=run_length_encoding(s);

	lint ans=0;
	while(R.size()>=2){
		bool changed=false;
		for(int i=R.size()-2;i>=0;i--){
			if(R[i].second>=2){
				for(int j=R.size()-1;j>i;j--){
					if(R[j].first!=R[i].first){
						ans+=R[j].second;
					}
					R[i].second+=R[j].second;
					R.pop_back();
				}
				changed=true;
				break;
			}
		}
		if(!changed) break;
	}
	printf("%lld\n",ans);

	return 0;
}
