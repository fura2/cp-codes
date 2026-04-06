#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x,y,r;
	{
		double xx,yy,rr; cin>>xx>>yy>>rr;
		x=lround(xx*1e4);
		y=lround(yy*1e4);
		r=lround(rr*1e4);
	}

	lint ans=0;
	for(lint i=-2e9;i<=2e9;i+=1e4){
		if(abs(i-y)<=r){
			lint dx=sqrt((long double)(r*r-(i-y)*(i-y))); // double 版の sqrt だと精度が足りなくて WA
			while((dx+1)*(dx+1)<=r*r-(i-y)*(i-y)) dx++;

			lint offset=1e12;
			ans+=(x+dx+offset)/10000-(x-dx-1+offset)/10000;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
