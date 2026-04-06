#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,k; scanf("%lld%lld",&n,&k);

	vector c(4,vector(3*n,0LL)); // c[i][j] = [x^j](1-x^n)^i/(1-x)^i
	c[0][0]=1;
	for(int i=1;i<=3;i++){
		c[i]=c[i-1];
		// /(1-x)
		rep(j,3*n-1) c[i][j+1]+=c[i][j];
		// *(1-x^n)
		for(int j=3*n-1;j>=n;j--) c[i][j]-=c[i][j-n];
	}

	int sum;
	for(sum=0;sum<3*n;sum++){
		if(k<=c[3][sum]) break;
		k-=c[3][sum];
	}

	int x;
	for(x=0;x<n;x++){
		if(k<=c[2][sum-x]) break;
		k-=c[2][sum-x];
	}

	int y,z;
	for(y=0;y<n;y++){
		z=sum-x-y;
		if(0<=z && z<n) k--;
		if(k==0) break;
	}

	printf("%d %d %d\n",x+1,y+1,z+1);

	return 0;
}
