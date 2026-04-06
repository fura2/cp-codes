#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,a,b; cin>>n>>a>>b;
	cout<<n/(a+b)*a+min(n%(a+b),a)<<'\n';
	return 0;
}
