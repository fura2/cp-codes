#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; cin>>n>>m;
	string A[50],B[50];
	rep(i,n) cin>>A[i];
	rep(i,m) cin>>B[i];

	rep(i,n-m+1) rep(j,n-m+1) {
		bool ok=true;
		rep(y,m) rep(x,m) if(A[i+y][j+x]!=B[y][x]) ok=false;
		if(ok) return cout<<"Yes\n",0;
	}
	cout<<"No\n";

	return 0;
}
