#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,m; cin>>n>>m;
	if(n>m) swap(n,m);
	if(n==1 && m==1){
		cout<<1<<endl;
	}
	else if(n==1){
		cout<<m-2<<endl;
	}
	else{
		cout<<(n-2)*(m-2)<<endl;
	}

	return 0;
}
