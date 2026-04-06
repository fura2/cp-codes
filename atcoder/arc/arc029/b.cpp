#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-3;
const double PI=acos(-1);

double a,b,h,w;

bool check(double theta){
	return a*cos(theta)+b*sin(theta)<h+EPS
		&& a*sin(theta)+b*cos(theta)<w+EPS;
}

int main(){
	scanf("%lf%lf",&a,&b);
	if(a>b) swap(a,b);

	int q; scanf("%d",&q);
	rep(_,q){
		scanf("%lf%lf",&h,&w);
		if(h>w) swap(h,w);

		if(h<a){ puts("NO"); continue; }

		puts(check(0) || check(PI/2)
		|| (h*h<=a*a+b*b && check(asin(h/hypot(a,b))-atan2(a,b)))
		|| (w*w<=a*a+b*b && check(PI-asin(w/hypot(a,b))-atan2(b,a)))?"YES":"NO");
	}

	return 0;
}
