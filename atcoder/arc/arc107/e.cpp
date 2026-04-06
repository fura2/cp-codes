#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

random_device seed_gen;
mt19937 rng(seed_gen());

int mex(int x,int y){
	rep(z,3) if(z!=x && z!=y) return z;
	return -1;
}

int main(){
// experiment
/*
	int n=30;
	vector a(n,vector(n,0));
	rep(i,n) a[i][0]=rng()%3;
	rep(j,n) a[0][j]=rng()%3;
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			a[i][j]=mex(a[i-1][j],a[i][j-1]);
		}
	}
	rep(i,n) rep(j,n) printf("%d%c",a[i][j],j<n-1?' ':'\n');
*/
	int n; scanf("%d",&n);

	if(n<10){
		vector a(n,vector(n,0));
		rep(j,n) scanf("%d",&a[0][j]);
		rep(i,n-1) scanf("%d",&a[i+1][0]);

		rep(i,n-1) rep(j,n-1) a[i+1][j+1]=mex(a[i][j+1],a[i+1][j]);

		int ans[3]={};
		rep(i,n) rep(j,n) ans[a[i][j]]++;
		printf("%d %d %d\n",ans[0],ans[1],ans[2]);
		return 0;
	}

	vector a(n,vector(10,0));
	rep(i,10) a[i].resize(n);
	rep(j,n) scanf("%d",&a[0][j]);
	rep(i,n-1) scanf("%d",&a[i+1][0]);

	for(int i=1;i<10;i++){
		for(int j=1;j<n;j++){
			a[i][j]=mex(a[i-1][j],a[i][j-1]);
		}
	}
	for(int j=1;j<10;j++){
		for(int i=10;i<n;i++){
			a[i][j]=mex(a[i-1][j],a[i][j-1]);
		}
	}

	lint ans[3]={};
	rep(i,n){
		rep(j,n){
			if(i>=10 && j>=10) break;
			ans[a[i][j]]++;
		}
	}
	for(int j=9;j<n;j++){
		ans[a[9][j]]+=n-j-1;
	}
	for(int i=10;i<n;i++){
		ans[a[i][9]]+=n-i-1;
	}
	printf("%lld %lld %lld\n",ans[0],ans[1],ans[2]);

	return 0;
}
