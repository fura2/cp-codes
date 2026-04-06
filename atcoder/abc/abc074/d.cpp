#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; cin>>n;
	int d[300][300];
	rep(i,n) rep(j,n) cin>>d[i][j];

	bool ok=true;
	rep(k,n) rep(i,n) rep(j,n) if(d[i][j]>d[i][k]+d[k][j]) ok=false;
	if(!ok){ cout<<-1<<endl; return 0; }

	bool need[300][300];
	rep(i,n) rep(j,n) need[i][j]=true;
	rep(k,n) rep(i,n) rep(j,n) if(k!=i && k!=j && d[i][j]==d[i][k]+d[k][j]) need[i][j]=false;

	lint ans=0;
	rep(i,n) rep(j,n) if(need[i][j]) ans+=d[i][j];
	cout<<ans/2<<endl;

	return 0;
}
