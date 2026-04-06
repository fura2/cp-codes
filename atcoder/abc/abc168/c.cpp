#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int main(){
	double a,b,h,m; cin>>a>>b>>h>>m;

	double t=abs(30*(h+m/60)-6*m)*PI/180;
	t=min(t,2*PI-t);
	printf("%.12f\n",sqrt(max(a*a+b*b-2*a*b*cos(t),0.0)));

	return 0;
}
