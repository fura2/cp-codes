#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<double> x(n),r(n),h(n);
	rep(i,n) scanf("%lf%lf%lf",&x[i],&r[i],&h[i]);

	rep(_,q){
		double a,b; scanf("%lf%lf",&a,&b);
		double ans=0;
		rep(i,n){
			double x1=max(x[i],a),x2=min(x[i]+h[i],b);
			if(x1<x2){
				double R;
				R=r[i]*(x[i]+h[i]-x1)/h[i];
				ans+=PI*R*R*(x[i]+h[i]-x1)/3.0;
				R=r[i]*(x[i]+h[i]-x2)/h[i];
				ans-=PI*R*R*(x[i]+h[i]-x2)/3.0;
			}
		}
		printf("%.9f\n",ans);
	}

	return 0;
}
