#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; cin>>a>>b;
	string B[100];
	rep(i,100) B[i]=string(50,'.')+string(50,'#');

	a--; b--;
	rep(j,25) rep(i,50) if(b>0) B[2*i][   2*j]='#', b--;
	rep(j,25) rep(i,50) if(a>0) B[2*i][99-2*j]='.', a--;

	cout<<"100 100"<<endl;
	rep(i,100) cout<<B[i]<<endl;

	return 0;
}
