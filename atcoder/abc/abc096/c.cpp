#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

int main(){
	int h,w; cin>>h>>w;
	string B[50];
	rep(i,h) cin>>B[i];

	rep(i,h) rep(j,w) if(B[i][j]=='#') {
		bool ok=false;
		rep(k,4){
			int y=i+dy[k],x=j+dx[k];
			if(0<=y && y<h && 0<=x && x<w && B[y][x]=='#') ok=true;
		}
		if(!ok){ cout<<"No"<<endl; return 0; }
	}
	cout<<"Yes"<<endl;

	return 0;
}
