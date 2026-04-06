#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; cin>>n>>m;
	int a[50],b[50],c[50],d[50];
	rep(i,n) cin>>a[i]>>b[i];
	rep(i,m) cin>>c[i]>>d[i];

	rep(i,n){
		int j=0;
		rep(k,m) if(abs(a[i]-c[k])+abs(b[i]-d[k])<abs(a[i]-c[j])+abs(b[i]-d[j])) j=k;
		cout<<j+1<<'\n';
	}

	return 0;
}
