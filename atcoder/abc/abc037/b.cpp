#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; cin>>n>>q;
	int a[100]={};
	rep(i,q){
		int l,r,t; cin>>l>>r>>t; l--;
		for(int j=l;j<r;j++) a[j]=t;
	}
	rep(i,n) cout<<a[i]<<endl;

	return 0;
}
