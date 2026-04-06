#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;
	vector<int> a(n);
	rep(i,n) cin>>a[i];

	int ans=0;
	rep(k1,k+1) rep(k2,k-k1+1) if(k1+k2<=n) {
		vector<int> b;
		rep(i,k1) b.emplace_back(a[i]);
		rep(i,k2) b.emplace_back(a[n-i-1]);
		sort(b.begin(),b.end(),greater<int>());
		int r=k-(k1+k2);
		while(r>0 && !b.empty() && b.back()<0) b.pop_back(), r--;
		ans=max(ans,accumulate(b.begin(),b.end(),0));
	}
	cout<<ans<<endl;

	return 0;
}
