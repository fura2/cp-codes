#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<pair<int,string>> a(n);
	rep(i,n) cin>>a[i].second>>a[i].first;

	sort(a.begin(),a.end());

	cout<<a[n-2].second<<'\n';

	return 0;
}
