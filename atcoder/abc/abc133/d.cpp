#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];

	long long tmp=0;
	rep(i,n){
		if(i%2==0) tmp+=a[i];
		else       tmp-=a[i];
	}

	vector<int> x(n);
	x[0]=tmp;
	rep(i,n-1) x[i+1]=2*a[i]-x[i];
	rep(i,n) cout<<x[i]<<" ";

	return 0;
}
