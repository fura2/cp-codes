#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,x; cin>>a>>b>>c>>x;
	int ans=0;
	rep(i,a+1) rep(j,b+1) rep(k,c+1) if(i*500+j*100+k*50==x) ans++;
	cout<<ans<<endl;

	return 0;
}
