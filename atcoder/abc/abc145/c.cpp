#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int x[8],y[8];
	rep(i,n) cin>>x[i]>>y[i];

	int p[8];
	rep(i,n) p[i]=i;
	double ans=0;
	do{
		rep(i,n-1) ans+=hypot(x[p[i]]-x[p[i+1]],y[p[i]]-y[p[i+1]]);
	}while(next_permutation(p,p+n));
	rep(i,n) ans/=i+1;
	cout<<setprecision(9)<<ans<<'\n';

	return 0;
}
