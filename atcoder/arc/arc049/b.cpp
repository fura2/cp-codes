#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<double> x(n),y(n),c(n);
	rep(i,n) scanf("%lf%lf%lf",&x[i],&y[i],&c[i]);

	double lo=0,hi=1e9;
	rep(_,50){
		double mi=(lo+hi)/2;

		double l=-1e9,r=1e9,t=-1e9,b=1e9;
		rep(i,n){
			l=max(l,x[i]-mi/c[i]);
			r=min(r,x[i]+mi/c[i]);
			t=max(t,y[i]-mi/c[i]);
			b=min(b,y[i]+mi/c[i]);
		}
		if(l<r && t<b) hi=mi;
		else           lo=mi;
	}
	printf("%.9f\n",lo);

	return 0;
}
