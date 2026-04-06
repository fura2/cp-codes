#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	bool ok=false;
	rep(i,100) rep(j,100) if(4*i+7*j==n) ok=true;
	cout<<(ok?"Yes":"No")<<endl;

	return 0;
}
