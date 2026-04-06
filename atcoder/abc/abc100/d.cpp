#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; cin>>n>>m;
	vector<long long> x(n),y(n),z(n);
	rep(i,n) cin>>x[i]>>y[i]>>z[i];

	long long ans=0;
	rep(_,2){
		rep(__,2){
			rep(___,2){
				vector<long long> a(n);
				rep(i,n) a[i]=x[i]+y[i]+z[i];
				sort(a.begin(),a.end());
				ans=max(ans,accumulate(a.begin()+n-m,a.end(),0LL));
				rep(i,n) z[i]*=-1;
			}
			rep(i,n) y[i]*=-1;
		}
		rep(i,n) x[i]*=-1;
	}
	cout<<ans<<endl;

	return 0;
}
