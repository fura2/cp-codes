#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double n,k; scanf("%lf%lf",&n,&k);
	printf("%.10f\n",(6*(k-1)*(n-k)+3*(n-1)+1)/(n*n*n));
	return 0;
}
