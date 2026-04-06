#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;

	vector<int> cnt(n);
	rep(i,n){
		int a; cin>>a; a--;
		cnt[a]++;
	}
	sort(cnt.rbegin(),cnt.rend());

	int ans=0;
	rep(i,n-k) ans+=cnt[k+i];
	cout<<ans<<endl;

	return 0;
}
