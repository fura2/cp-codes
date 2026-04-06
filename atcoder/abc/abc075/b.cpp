#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	string B[50];
	rep(i,h) cin>>B[i];

	rep(i,h) rep(j,w) if(B[i][j]=='.') {
		int cnt=0;
		rep(k,3) rep(l,3) {
			int y=i+k-1,x=j+l-1;
			if(0<=y && y<h && 0<=x && x<w && B[y][x]=='#') cnt++;
		}
		B[i][j]='0'+cnt;
	}

	rep(i,h) cout<<B[i]<<endl;

	return 0;
}
