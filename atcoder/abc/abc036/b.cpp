#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	string B[50];
	rep(i,n) cin>>B[i];

	rep(i,n){ rep(j,n) cout<<B[n-j-1][i]; cout<<endl; }

	return 0;
}
