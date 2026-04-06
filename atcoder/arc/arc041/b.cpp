#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	int a[500][500]={},b[500][500];
	rep(i,h){
		string s; cin>>s;
		rep(j,w) b[i][j]=s[j]-'0';
	}

	for(int j=1;j<w-1;j++){
		a[1][j]=b[0][j];
		a[h-2][j]=b[h-1][j];
	}
	for(int i=1;i<h-1;i++){
		a[i][1]=b[i][0];
		a[i][w-2]=b[i][w-1];
	}

	for(int d=1;d<min(h,w)/2;d++){
		for(int j=d+1;j<w-d-1;j++){
			a[d+1][j]=b[d][j]-a[d-1][j]-a[d][j-1]-a[d][j+1];
			a[h-d-2][j]=b[h-d-1][j]-a[h-d][j]-a[h-d-1][j-1]-a[h-d-1][j+1];
		}
		for(int i=d+1;i<h-d-1;i++){
			a[i][d+1]=b[i][d]-a[i][d-1]-a[i-1][d]-a[i+1][d];
			a[i][w-d-2]=b[i][w-d-1]-a[i][w-d]-a[i-1][w-d-1]-a[i+1][w-d-1];
		}
	}
	rep(i,h) rep(j,w) printf("%d%s",a[i][j],j<w-1?"":"\n");

	return 0;
}
