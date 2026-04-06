#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int main(){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);

	double lo=0,hi=200;
	rep(_,50){
		double mi=(lo+hi)/2;
		if(a*mi+b*sin(c*PI*mi)-100<0) lo=mi; else hi=mi;
	}
	printf("%.15f\n",lo);

	return 0;
}
