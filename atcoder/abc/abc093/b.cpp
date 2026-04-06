#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,k; cin>>a>>b>>k;
	vector<int> ans;
	rep(i,k){
		if(a+i<=b) ans.emplace_back(a+i);
		if(a<=b-i) ans.emplace_back(b-i);
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());

	for(int x:ans) cout<<x<<endl;

	return 0;
}
