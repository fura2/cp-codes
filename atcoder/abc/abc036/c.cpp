#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a[100000]; cin>>n;
	rep(i,n) cin>>a[i];

	vector<int> X(a,a+n);
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	rep(i,n) cout<<lower_bound(X.begin(),X.end(),a[i])-X.begin()<<endl;

	return 0;
}
