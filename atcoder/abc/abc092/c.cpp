#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<int> a(n+3);
	rep(i,n) cin>>a[i+1];

	int sum=0;
	rep(i,n+1) sum+=abs(a[i+1]-a[i]);
	rep(i,n) cout<<sum-abs(a[i+1]-a[i])-abs(a[i+2]-a[i+1])+abs(a[i+2]-a[i])<<endl;

	return 0;
}
