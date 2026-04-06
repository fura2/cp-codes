#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,p,q,r; cin>>n>>m>>p>>q>>r;
	vector<int> x(r),y(r),z(r);
	rep(i,r) cin>>x[i]>>y[i]>>z[i], x[i]--, y[i]--;

	int ans=0;
	rep(S,1<<n){
		int pc=0;
		rep(i,n) if(S>>i&1) pc++;
		if(pc!=p) continue;

		int val[18]={};
		rep(i,r) if(S>>x[i]&1) val[y[i]]+=z[i];
		sort(val,val+m);
		ans=max(ans,accumulate(val+m-q,val+m,0));
	}
	cout<<ans<<'\n';

	return 0;
}
