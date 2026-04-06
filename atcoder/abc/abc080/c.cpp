#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1e9;

int main(){
	int n,f[100][10],p[100][11];
	cin>>n;
	rep(i,n) rep(j,10) cin>>f[i][j];
	rep(i,n) rep(j,11) cin>>p[i][j];

	int ans=-INF;
	for(int S=1;S<1024;S++){
		int sum=0;
		rep(i,n){
			int cnt=0;
			rep(j,10) if((S>>j&1) && f[i][j]==1) cnt++;
			sum+=p[i][cnt];
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;

	return 0;
}
