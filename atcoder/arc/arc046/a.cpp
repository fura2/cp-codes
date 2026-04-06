#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	cout<<string((n+8)/9,'1'+(n-1)%9)<<'\n';
	return 0;
}
