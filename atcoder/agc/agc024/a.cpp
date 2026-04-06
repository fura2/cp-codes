#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c,k; cin>>a>>b>>c>>k;
	cout<<(k%2==0?a-b:b-a)<<'\n';
	return 0;
}
