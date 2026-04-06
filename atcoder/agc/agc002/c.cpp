#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,L; cin>>n>>L;
	int a[100000];
	rep(i,n) cin>>a[i];

	rep(i,n-1) if(a[i]+a[i+1]>=L) {
		cout<<"Possible"<<endl;
		rep(j,i) cout<<j+1<<endl;
		for(int j=n-2;j>=i;j--) cout<<j+1<<endl;
		return 0;
	}
	cout<<"Impossible"<<endl;

	return 0;
}
