#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int g=0;
	rep(i,n){
		int X,Y,Z,m; cin>>X>>Y>>Z>>m;
		int x1=X,x2=0,y1=Y,y2=0,z1=Z,z2=0;
		rep(j,m){
			int x,y,z; cin>>x>>y>>z;
			x1=min(x1,x);
			x2=max(x2,x);
			y1=min(y1,y);
			y2=max(y2,y);
			z1=min(z1,z);
			z2=max(z2,z);
		}
		g^=x1;
		g^=X-x2-1;
		g^=y1;
		g^=Y-y2-1;
		g^=z1;
		g^=Z-z2-1;
	}
	cout<<(g?"WIN":"LOSE")<<endl;

	return 0;
}
