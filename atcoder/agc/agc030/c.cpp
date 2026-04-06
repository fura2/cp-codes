#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k; scanf("%d",&k);

	if(k==1){
		puts("1\n1");
		return 0;
	}

	int n,m,r; // k = 2*m + r s.t. n = m + r is even
	for(r=0;r<4;r++){
		if(r<=k && (k-r)%2==0){
			m=(k-r)/2;
			n=m+r;
			if(n%2==0) break;
		}
	}
	assert(r<4);

	vector B(n,vector(n,0));
	rep(d,n) rep(i,n) {
		if(d<m){
			B[i][(i+d)%n]=2*d+i%2+1;
		}
		else{
			B[i][(i+d)%n]=m+d+1;
		}
	}

	printf("%d\n",n);
	rep(i,n) rep(j,n) printf("%d%c",B[i][j],j<n-1?' ':'\n');

	return 0;
}
