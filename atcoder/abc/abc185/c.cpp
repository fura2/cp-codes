#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);

	lint C[200][200]={};
	rep(i,n){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	printf("%lld\n",C[n-1][11]);

	return 0;
}
