#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,c; cin>>n>>m>>c;
	int a[20][20],b[20];
	rep(i,m) cin>>b[i];
	rep(i,n) rep(j,m) cin>>a[i][j];

	int ans=0;
	rep(i,n) if(inner_product(a[i],a[i]+m,b,0)+c>0) ans++;
	cout<<ans<<endl;

	return 0;
}
