#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> c(n);
	rep(i,n) scanf("%d",&c[i]);

	double fact[101]={1};
	rep(i,n) fact[i+1]=fact[i]*(i+1);

	double choose[101][101]={};
	rep(i,n+1) choose[i][0]=1;
	rep(i,n) rep(j,i+1) choose[i+1][j+1]=choose[i][j+1]+choose[i][j];

	double ans=0;
	rep(i,n){
		int cnt=0;
		rep(j,n) if(j!=i && c[i]%c[j]==0) cnt++;

		rep(p,n){ // コイン i を左から p 番目に置く
			for(int k=0;k<=min(p,cnt);k+=2){ // コイン i の左にその約数を k 個置く
				ans+=choose[p][k]*choose[n-p-1][cnt-k]*fact[cnt]*fact[n-cnt-1]/fact[n-1]/n;
			}
		}
	}
	printf("%.9f\n",ans);

	return 0;
}
