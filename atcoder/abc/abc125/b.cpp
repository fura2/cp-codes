#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,v[20],c[20]; cin>>n;
	rep(i,n) cin>>v[i];
	rep(i,n) cin>>c[i];

	int ans=0;
	rep(i,n) if(v[i]>c[i]) ans+=v[i]-c[i];
	cout<<ans<<endl;

	return 0;
}
