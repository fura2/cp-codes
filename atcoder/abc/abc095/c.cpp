#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,x,y; cin>>a>>b>>c>>x>>y;

	int ans=0;
	if(x>0 && y>0 && 2*c<a+b){
		int z=min(x,y);
		x-=z;
		y-=z;
		ans+=2*c*z;
	}
	ans+=min(a,2*c)*x;
	ans+=min(b,2*c)*y;
	cout<<ans<<endl;

	return 0;
}
