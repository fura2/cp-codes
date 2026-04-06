#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<int> l(n);
	rep(i,n) cin>>l[i];

	sort(l.begin(),l.end());

	int ans=0;
	rep(j,n) rep(i,j) {
		ans+=lower_bound(l.begin()+j+1,l.end(),l[i]+l[j])
			-upper_bound(l.begin()+j+1,l.end(),abs(l[i]-l[j]));
	}
	cout<<ans<<endl;

	return 0;
}
