#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int main(){
	int n; scanf("%d",&n);
	double x0,y0,x1,y1; scanf("%lf%lf%lf%lf",&x0,&y0,&x1,&y1);

	double vx=x1-x0,vy=y1-y0;
	double r=hypot(vx,vy)/2;
	double s=2*r*sin(PI/n);
	double theta=-(PI/2-PI/n);
	tie(vx,vy)=make_pair(vx/hypot(vx,vy),vy/hypot(vx,vy));
	tie(vx,vy)=make_pair(vx*cos(theta)-vy*sin(theta),vx*sin(theta)+vy*cos(theta));
	printf("%.9f %.9f\n",x0+s*vx,y0+s*vy);

	return 0;
}
