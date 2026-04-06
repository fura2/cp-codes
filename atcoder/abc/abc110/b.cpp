#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,X,Y; cin>>n>>m>>X>>Y;
	int x[100],y[100];
	rep(i,n) cin>>x[i];
	rep(i,m) cin>>y[i];

	for(int z=X+1;z<=Y;z++){
		bool ok=true;
		rep(i,n) if(x[i]>=z) ok=false;
		rep(i,m) if(y[i]< z) ok=false;
		if(ok){ cout<<"No War"<<endl; return 0; }
	}
	cout<<"War"<<endl;

	return 0;
}
