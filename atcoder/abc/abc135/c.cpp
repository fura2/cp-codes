#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<int> a(n+1),b(n);
	rep(i,n+1) cin>>a[i];
	rep(i,n) cin>>b[i];

	long long ans=0;
	rep(i,n){
		int x=min(a[i],b[i]);
		b[i]-=x;
		ans+=x;
		int y=min(a[i+1],b[i]);
		a[i+1]-=y;
		ans+=y;
	}
	cout<<ans<<endl;

	return 0;
}
