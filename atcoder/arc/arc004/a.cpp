#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int x[100],y[100];
	rep(i,n) cin>>x[i]>>y[i];

	double d=0;
	rep(i,n) rep(j,i) d=max(d,hypot(x[i]-x[j],y[i]-y[j]));
	cout<<d<<endl;

	return 0;
}
