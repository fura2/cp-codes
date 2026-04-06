#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double r,x,y; cin>>r>>x>>y;

	double z=floor(hypot(x,y)+0.5);
	if(x*x+y*y==z*z && int(z)%int(r)==0){
		cout<<int(z)/int(r)<<'\n';
		return 0;
	}

	cout<<max(int(ceil(hypot(x,y)/r)),2)<<'\n';

	return 0;
}
