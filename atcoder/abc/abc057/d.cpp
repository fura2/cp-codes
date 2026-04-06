#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<vector<lint>> nCr;
void binom(int n){
	nCr.assign(n+1,vector<lint>(n+1));
	rep(i,n+1) nCr[i][0]=1;
	rep(i,n) rep(j,i+1) nCr[i+1][j+1]=nCr[i][j+1]+nCr[i][j];
}

int main(){
	binom(50);

	int n,a,b; cin>>n>>a>>b;
	lint v[50];
	rep(i,n) cin>>v[i];

	sort(v,v+n);

	lint ans1=0,ans2=1;
	for(int m=a;m<=b;m++){
		lint sum=accumulate(v+n-m,v+n,0LL);
		if(sum*ans2>m*ans1){
			ans1=sum;
			ans2=m;
		}
	}

	lint cnt=0;
	for(int m=a;m<=b;m++){
		lint sum=accumulate(v+n-m,v+n,0LL);
		if(sum*ans2==m*ans1){
			cnt+=nCr[count(v,v+n,v[n-m])][count(v+n-m,v+n,v[n-m])];
		}
	}
	cout<<setprecision(9)<<1.0*ans1/ans2<<'\n'<<cnt<<'\n';

	return 0;
}
