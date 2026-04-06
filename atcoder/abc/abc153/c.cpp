#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,k; cin>>n>>k;
	vector<lint> h(n);
	rep(i,n) cin>>h[i];

	sort(h.begin(),h.end());

	cout<<accumulate(h.begin(),h.begin()+n-min(k,n),0LL)<<'\n';

	return 0;
}
