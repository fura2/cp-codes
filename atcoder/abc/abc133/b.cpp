#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d; cin>>n>>d;
	int x[10][10];
	rep(i,n) rep(j,d) cin>>x[i][j];

	int ans=0;
	rep(i,n) rep(j,i) {
		int a=0;
		rep(k,d) a+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
		int b=(int)(sqrt(a)+0.5);
		if(b*b==a) ans++;
	}
	cout<<ans<<endl;

	return 0;
}
