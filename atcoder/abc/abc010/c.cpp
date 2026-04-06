#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;
const double INF=1e77;

int main(){
	int sx,sy,gx,gy,T,v,n; scanf("%d%d%d%d%d%d%d",&sx,&sy,&gx,&gy,&T,&v,&n);

	double d_min=INF;
	rep(i,n){
		int x,y; scanf("%d%d",&x,&y);
		d_min=min(d_min,hypot(x-sx,y-sy)+hypot(x-gx,y-gy));
	}

	puts(d_min/v<T+EPS?"YES":"NO");

	return 0;
}
