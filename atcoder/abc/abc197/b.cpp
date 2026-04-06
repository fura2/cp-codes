#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,x,y; cin>>h>>w>>x>>y; x--; y--;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int ans=1;
	for(int i=x-1;i>=0;i--){
		if(B[i][y]=='#') break;
		ans++;
	}
	for(int i=x+1;i<h;i++){
		if(B[i][y]=='#') break;
		ans++;
	}
	for(int j=y-1;j>=0;j--){
		if(B[x][j]=='#') break;
		ans++;
	}
	for(int j=y+1;j<w;j++){
		if(B[x][j]=='#') break;
		ans++;
	}
	printf("%d\n",ans);

	return 0;
}
