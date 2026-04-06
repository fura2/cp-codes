#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m; cin>>n>>m;
	pair<int,int> a[100000];
	rep(i,n) cin>>a[i].first>>a[i].second;

	sort(a,a+n);

	lint ans=0;
	rep(i,n) while(a[i].second>0 && m>0) ans+=a[i].first, a[i].second--, m--;
	cout<<ans<<endl;

	return 0;
}
