#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long double EPS=1e-10;
const long double PI=acos(-1L);

struct point{ long double x,y; };

int main(){
	int n; scanf("%d",&n);
	point p[2000];
	rep(i,n) scanf("%Lf%Lf",&p[i].x,&p[i].y);

	lint right=0,obtuse=0;
	rep(i,n){
		long double phi[4000];
		rep(j,n) if(j!=i) {
			phi[j]=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
			if(phi[j]<0) phi[j]+=2*PI;
		}
		swap(phi[i],phi[n-1]);
		sort(phi,phi+n-1);
		rep(j,n-1) phi[n-1+j]=phi[j]+2*PI;

		rep(j,n-1){
			int idx1=lower_bound(phi+j,phi+2*n-2,phi[j]+PI/2-EPS)-phi;
			if(abs(phi[idx1]-phi[j]-PI/2)<EPS){
				right++;
				idx1++;
			}
			int idx2=lower_bound(phi+j,phi+2*n-2,phi[j]+PI+EPS)-phi;
			obtuse+=idx2-idx1;
		}
	}

	lint acute=n*(n-1LL)*(n-2)/6-right-obtuse;
	printf("%lld %lld %lld\n",acute,right,obtuse);

	return 0;
}
