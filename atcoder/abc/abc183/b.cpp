#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double sx,sy,gx,gy;
	cin>>sx>>sy>>gx>>gy;
	printf("%.9f\n",sx+sy*(gx-sx)/(sy+gy));
	return 0;
}
