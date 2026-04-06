#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int w,h,x,y; cin>>w>>h>>x>>y;
	cout<<setprecision(10)<<0.5*w*h<<' '<<(2*x==w&&2*y==h?1:0)<<endl;

	return 0;
}
