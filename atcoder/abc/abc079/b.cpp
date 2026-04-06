#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint l[99]={2,1};
	rep(i,97) l[i+2]=l[i]+l[i+1];

	int n; cin>>n;
	cout<<l[n]<<endl;

	return 0;
}
