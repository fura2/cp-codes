#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint MOD=1e9+7;

int main(){
	lint a,b,c; cin>>a>>b>>c;
	cout<<a*b%MOD*c%MOD<<endl;

	return 0;
}
