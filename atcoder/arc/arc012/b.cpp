#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	double va,vb,l; cin>>n>>va>>vb>>l;

	rep(i,n) l*=vb/va;

	cout<<setprecision(7)<<l<<endl;

	return 0;
}
