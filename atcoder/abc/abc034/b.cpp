#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	cout<<(n%2==0?n-1:n+1)<<'\n';
	return 0;
}
