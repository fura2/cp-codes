#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; cin>>n;
	vector<int> a(3*n);
	rep(i,3*n) cin>>a[i];

	multiset<lint> L(a.begin(),a.begin()+n);
	vector<lint> left(n+1);
	rep(i,n) left[0]+=a[i];
	rep(i,n){
		L.emplace(a[n+i]);
		lint x=*L.begin();
		L.erase(L.begin());
		left[i+1]=left[i]+a[n+i]-x;
	}

	multiset<lint> R(a.begin()+2*n,a.end());
	vector<lint> right(n+1);
	for(int i=n-1;i>=0;i--) right[n]+=a[2*n+i];
	for(int i=n-1;i>=0;i--){
		R.emplace(a[n+i]);
		lint x=*--R.end();
		R.erase(--R.end());
		right[i]=right[i+1]+a[n+i]-x;
	}

	lint ans=-1e15;
	rep(i,n+1) ans=max(ans,left[i]-right[i]);
	cout<<ans<<endl;

	return 0;
}
