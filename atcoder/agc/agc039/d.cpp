#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int main(){
	int n;
	double L,theta[3000]; cin>>n>>L;
	rep(i,n) cin>>theta[i], theta[i]*=2*PI/L;

	double xans=0,yans=0;
	rep(j,n) rep(i,j) {
		double phi=(theta[i]+theta[j])/2;
		xans+=(n-j+i-1)*cos(phi)+(j-i-1)*cos(phi+PI);
		yans+=(n-j+i-1)*sin(phi)+(j-i-1)*sin(phi+PI);
	}
	xans/=n*(n-1.)*(n-2)/6;
	yans/=n*(n-1.)*(n-2)/6;

	cout<<setprecision(10)<<xans<<' '<<yans<<endl;

	return 0;
}
