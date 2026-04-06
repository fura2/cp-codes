#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int ans=0;
	rep(i,h-1) rep(j,w-1) {
		int cnt=0;
		rep(x,2) rep(y,2) if(B[i+x][j+y]=='#') cnt++;
		if(cnt%2==1) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
