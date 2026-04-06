#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int w,h,n; cin>>w>>h>>n;
	int B[100][100]={};
	rep(_,n){
		int x,y,a; cin>>x>>y>>a;
		if     (a==1) rep(i,h) rep(j,x) B[i][j]=1;
		else if(a==2) rep(i,h) for(int j=x;j<w;j++) B[i][j]=1;
		else if(a==3) rep(j,w) rep(i,y) B[i][j]=1;
		else          rep(j,w) for(int i=y;i<h;i++) B[i][j]=1;
	}

	int ans=0;
	rep(i,h) rep(j,w) ans+=1-B[i][j];
	cout<<ans<<endl;

	return 0;
}
