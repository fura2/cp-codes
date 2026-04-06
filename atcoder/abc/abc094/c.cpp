#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<pair<int,int>> a(n);
	rep(i,n) cin>>a[i].first, a[i].second=i;

	sort(a.begin(),a.end());

	vector<int> ans(n);
	rep(i,n) ans[a[i].second]=a[i<n/2?n/2:n/2-1].first;
	rep(i,n) cout<<ans[i]<<endl;

	return 0;
}
