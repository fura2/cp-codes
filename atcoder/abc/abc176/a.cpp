#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x,t; cin>>n>>x>>t;
	cout<<(n+x-1)/x*t<<'\n';
	return 0;
}
