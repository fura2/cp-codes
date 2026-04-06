#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector a(n,vector(n,0));
	rep(i,n) rep(j,n) scanf("%d",&a[i][j]);

	int lo=-1,hi=1e9;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		vector cum(n+1,vector(n+1,0));
		rep(i,n) rep(j,n) {
			cum[i+1][j+1]+=cum[i+1][j]+cum[i][j+1]-cum[i][j]+(a[i][j]<=mi?1:0);
		}

		bool ok=false;
		rep(i,n-k+1) rep(j,n-k+1) {
			if(cum[i+k][j+k]-cum[i+k][j]-cum[i][j+k]+cum[i][j]>=(k*k+1)/2) ok=true;
		}
		if(ok) hi=mi;
		else   lo=mi;
	}
	printf("%d\n",hi);

	return 0;
}
