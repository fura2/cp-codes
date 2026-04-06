#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k,l[50]; cin>>n>>k;
	rep(i,n) cin>>l[i];

	sort(l,l+n);

	cout<<accumulate(l-k+n,l+n,0)<<endl;

	return 0;
}
