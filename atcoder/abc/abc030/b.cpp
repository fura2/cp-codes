#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int main(){
	int n,m; cin>>n>>m;
	n%=12;
	double d=abs(n/12.0+m/60.0/12-m/60.0)*360;
	cout<<min(d,360-d)<<'\n';
	return 0;
}
