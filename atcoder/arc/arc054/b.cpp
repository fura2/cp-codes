#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double p; scanf("%lf",&p);
	double x=max(-1.5*log(1.5/(p*log(2)))/log(2),0.0);
	printf("%.9f\n",x+p*pow(2,-x/1.5));
	return 0;
}
