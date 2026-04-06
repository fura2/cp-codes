#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x; cin>>x;

	lint m=(x+10)/11,n=(x+4)/11;
	cout<<min(2*m,2*n+1)<<'\n';

	return 0;
}
