#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int f(lint x){ return x<10?x:f(x/10)+x%10; }

int main(){
	lint n; cin>>n;

	vector<lint> ans;
	rep(d,200) if(n-d>0 && (n-d)+f(n-d)==n) ans.emplace_back(n-d);

	sort(ans.begin(),ans.end());

	cout<<ans.size()<<'\n';
	for(lint x:ans) cout<<x<<'\n';

	return 0;
}
