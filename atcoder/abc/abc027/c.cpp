#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;

	int m=0;
	while((1LL<<m)<=n) m++;

	lint x=1;
	while(1){
		x=2*x+m%2;
		if(x>n){ puts("Aoki"); break; }
		x=2*x+1-m%2;
		if(x>n){ puts("Takahashi"); break; }
	}

	return 0;
}
