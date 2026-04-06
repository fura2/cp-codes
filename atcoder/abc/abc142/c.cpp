#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	pair<int,int> a[100000];
	rep(i,n) cin>>a[i].first, a[i].second=i+1;

	sort(a,a+n);

	rep(i,n) cout<<a[i].second<<" ";

	return 0;
}
