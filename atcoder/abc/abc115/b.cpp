#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,p[10]; cin>>n;
	rep(i,n) cin>>p[i];

	sort(p,p+n);

	cout<<accumulate(p,p+n,0)-p[n-1]/2<<endl;

	return 0;
}
