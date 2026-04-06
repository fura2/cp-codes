#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	vector<string> A(h),B(h);
	rep(i,h) cin>>A[i];
	rep(i,h) cin>>B[i];

	rep(i,h) rep(j,w) {
		bool ok=true;
		rep(x,h) rep(y,w) if(A[(x+i)%h][(y+j)%w]!=B[x][y]) ok=false;
		if(ok){
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";

	return 0;
}
