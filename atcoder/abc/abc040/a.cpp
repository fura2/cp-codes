#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x; cin>>n>>x;
	cout<<min(x-1,n-x)<<'\n';
	return 0;
}
