#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	double w[1000],p[1000];
	rep(i,n) scanf("%lf%lf",&w[i],&p[i]);

	double lo=0,hi=100,tmp[1000];
	rep(_,30){
		double mi=(lo+hi)/2;
		rep(i,n) tmp[i]=(p[i]-mi)*w[i];
		nth_element(tmp,tmp+k,tmp+n,greater<double>());
		if(accumulate(tmp,tmp+k,0.0)>0) lo=mi; else hi=mi;
	}
	printf("%.9f\n",lo);

	return 0;
}
