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
	int n; scanf("%d",&n);
	string s;
	rep(i,n){
		char c; scanf(" %c",&c);
		s+=c;
	}

	auto rle=run_length_encoding(s);
	if(rle.size()==1) return puts("-1"),0;

	if(rle.size()%2==1){
		rle[0].second+=rle.back().second;
		rle.pop_back();
	}

	int ans=0;
	for(auto p:rle) ans=max(ans,(p.second+1)/2);
	printf("%d\n",ans);

	return 0;
}
