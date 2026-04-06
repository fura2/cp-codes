#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int m;
	for(m=1;m*m<=n;m++);
	cout<<(m-1)*(m-1)<<'\n';

	return 0;
}
