#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint q,h,s,d,n; cin>>q>>h>>s>>d>>n;
	lint one=min({4*q,2*h,s});
	lint two=min({2*one,d});
	cout<<n/2*two+n%2*one<<'\n';
	return 0;
}
